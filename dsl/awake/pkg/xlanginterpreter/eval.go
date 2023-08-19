package xlanginterpreter

import (
	"fmt"

	"github.com/hebin/awake/pkg/xlang"
)

var (
	TRUE    = &Boolean{Value: true}
	FALSE   = &Boolean{Value: false}
	NULLOBJ = &Null{}
)

var builtins = map[string]*Builtin{
	"first": {
		Fn: func(args ...Object) Object {
			if len(args) != 1 {
				return newError("wrong number of arguments. got=%d, want=1", len(args))
			}
			if args[0].Type() != ARRAY_OBJ {
				return newError("argument to `first` must be ARRAY, got=%s", args[0].Type())
			}
			arr := args[0].(*Array)
			if len(arr.Elements) > 0 {
				return arr.Elements[0]
			}
			return NULLOBJ
		},
	},
	"last": {
		Fn: func(args ...Object) Object {
			if len(args) != 1 {
				return newError("wrong number of arguments. got=%d, want=1", len(args))
			}
			if args[0].Type() != ARRAY_OBJ {
				return newError("argument to `first` must be ARRAY, got=%s", args[0].Type())
			}
			arr := args[0].(*Array)
			if len(arr.Elements) > 0 {
				return arr.Elements[len(arr.Elements)-1]
			}
			return NULLOBJ
		},
	},
	"len": {
		Fn: func(args ...Object) Object {
			if len(args) != 1 {
				return newError("wrong number of arguments. got=%d, want=1", len(args))
			}
			switch arg := args[0].(type) {
			case *String:
				return &Integer{Value: int64(len(arg.Value))}
			case *Array:
				return &Integer{Value: int64(len(arg.Elements))}
			default:
				return newError("argument to `len` not supported, got %s", args[0].Type())
			}
		},
	},
	"puts": &Builtin{
		Fn: func(args ...Object) Object {
			for _, arg := range args {
				fmt.Println(arg.Inspect())
			}
			return NULLOBJ
		},
	},
}

func Eval(node xlang.Node, env *Environment) Object {
	switch node := node.(type) {
	case *xlang.Program:
		return evalProgram(node, env)
	case *xlang.LetStatement:
		val := Eval(node.Value, env)
		if isError(val) {
			return val
		}
		env.Set(node.Name.String(), val)
	case *xlang.CallExpression:
		function := Eval(node.Function, env)
		if isError(function) {
			return function
		}
		args := evalExpressions(node.Arguments, env)
		if len(args) == 1 && isError(args[0]) {
			return args[0]
		}
		return applyFunction(function, args)
	case *xlang.FunctionLiteral:
		params := node.Parameters
		body := node.Body
		return &Function{Parameters: params, Env: env, Body: body}
	case *xlang.ExpressionStatement:
		return Eval(node.Expression, env)
	case *xlang.BlockStatement:
		return evalBlockStatements(node, env)
	case *xlang.IfExpression:
		return evalIfExpression(node, env)
	case *xlang.ReturnStatement:
		val := Eval(node.ReturnValue, env)
		if isError(val) {
			return val
		}
		return &ReturnValue{Value: val}
	case *xlang.Identifier:
		return evalIdentifier(node, env)
	case *xlang.Boolean:
		{
			if node.Value {
				return TRUE
			}
			return FALSE
		}
	case *xlang.InflixExpression:
		{
			left := Eval(node.Left, env)
			right := Eval(node.Right, env)
			if isError(left) {
				return left
			}
			if isError(right) {
				return right
			}
			ret := evalInflixExpression(node.Operator, left, right)
			fmt.Println("ret", ret)
			return ret
		}
	case *xlang.PrefixExpression:
		{
			right := Eval(node.Right, env)
			if isError(right) {
				return right
			}
			return evalPrefixExpression(node.Operator, right)
		}
	case *xlang.IntegerLiteral:
		return &Integer{Value: node.Value}
	case *xlang.StringLiteral:
		return &String{Value: node.Value}
	case *xlang.ArrayLiteral:
		elements := evalExpressions(node.Elements, env)
		if len(node.Elements) == 1 && isError(elements[0]) {
			return elements[0]
		}
		return &Array{Elements: elements}
	case *xlang.IndexExpression:
		left := Eval(node.Left, env)
		if isError(left) {
			return left
		}
		index := Eval(node.Index, env)
		if isError(index) {
			return index
		}
		return evalIndexExpression(left, index)
	case *xlang.HashLiteral:
		return evalHashLiteral(node, env)
	}
	return nil
}

func evalPrefixExpression(operator string, right Object) Object {
	switch operator {
	case "!":
		return evalBangOperatorExpression(right)
	case "-":
		return evalMinusPrefixOperatorExpression(right)
	default:
		return newError("unknown operator: %s%s", operator, right.Type())
	}
}

func evalBangOperatorExpression(right Object) Object {
	switch right {
	case TRUE:
		return FALSE
	case FALSE:
		return TRUE
	case NULLOBJ:
		return TRUE
	default:
		return FALSE
	}
}

func evalMinusPrefixOperatorExpression(right Object) Object {
	if right.Type() != INTEGER {
		return newError("unknown operator: -%s", right.Type())
	}
	value := right.(*Integer).Value
	return &Integer{Value: -value}
}

func evalInflixExpression(operator string, left Object, right Object) Object {
	switch {
	case left.Type() != right.Type():
		return newError("type mismatch: %s %s %s", left.Type(), operator, right.Type())
	case left.Type() == STRING_OBJ && right.Type() == STRING_OBJ:
		return evalStringInflixExpression(operator, left, right)
	case left.Type() == INTEGER && right.Type() == INTEGER:
		return evalIntegerInflixExpression(operator, left, right)
	case operator == "==":
		return nativeBool2BoolObject(left == right)
	case operator == "!=":
		return nativeBool2BoolObject(left != right)
	default:
		return newError("unknown operator: %s %s %s", left.Type(), operator, right.Type())
	}
}

func evalIntegerInflixExpression(operator string, left Object, right Object) Object {
	leftVal := left.(*Integer).Value
	rightVal := right.(*Integer).Value
	switch operator {
	case "+":
		return &Integer{Value: leftVal + rightVal}
	case "-":
		return &Integer{Value: leftVal - rightVal}
	case "*":
		return &Integer{Value: leftVal * rightVal}
	case "/":
		return &Integer{Value: leftVal / rightVal}
	case ">":
		return nativeBool2BoolObject(leftVal > rightVal)
	case "<":
		return nativeBool2BoolObject(leftVal < rightVal)
	case "==":
		return nativeBool2BoolObject(leftVal == rightVal)
	case "!=":
		return nativeBool2BoolObject(leftVal != rightVal)
	default:
		return newError("unknown operator: %s %s %s", left.Type(), operator, right.Type())
	}
}

func nativeBool2BoolObject(b bool) *Boolean {
	if b {
		return TRUE
	}
	return FALSE
}

func evalIfExpression(ie *xlang.IfExpression, env *Environment) Object {
	condition := Eval(ie.Condition, env)
	if isError(condition) {
		return condition
	}
	if isTruthy(condition) {
		return Eval(ie.Consequence, env)
	} else if ie.Alternative != nil {
		return Eval(ie.Alternative, env)
	} else {
		return NULLOBJ
	}
}

func isTruthy(obj Object) bool {
	switch obj {
	case NULLOBJ:
		return false
	case TRUE:
		return true
	case FALSE:
		return false
	default:
		return true
	}
}

func evalProgram(program *xlang.Program, env *Environment) Object {
	var result Object
	for _, statement := range program.Statements {
		result = Eval(statement, env)
		if returnValue, ok := result.(*ReturnValue); ok {
			return returnValue.Value
		}
		if returnValue, ok := result.(*Error); ok {
			return returnValue
		}
	}
	return result
}

func evalBlockStatements(block *xlang.BlockStatement, env *Environment) Object {
	var result Object
	for _, statement := range block.Statements {
		result = Eval(statement, env)
		if result != nil && result.Type() == RETURN_OBJ {
			return result
		}
		if result != nil && result.Type() == ERROR_OBJ {
			return result
		}
	}
	return result
}

func newError(format string, a ...interface{}) *Error {
	return &Error{Message: fmt.Sprintf(format, a...)}
}

func isError(obj Object) bool {
	if obj != nil {
		return obj.Type() == ERROR_OBJ
	}
	return false
}

func evalIdentifier(node *xlang.Identifier, env *Environment) Object {
	if val, ok := env.Get(node.Value); ok {
		return val
	}
	if builtin, ok := builtins[node.Value]; ok {
		return builtin
	}
	return newError("identifier not found: " + node.Value)
}

func evalExpressions(exps []xlang.Expression, env *Environment) []Object {
	var result []Object
	for _, e := range exps {
		evaluated := Eval(e, env)
		if isError(evaluated) {
			return []Object{evaluated}
		}
		result = append(result, evaluated)
	}
	return result
}

func applyFunction(fn Object, args []Object) Object {
	switch fn := fn.(type) {
	case *Function:
		extendedEnv := extendFunctionEnv(fn, args)
		evaluated := Eval(fn.Body, extendedEnv)
		return unwrapReturnValue(evaluated)
	case *Builtin:
		return fn.Fn(args...)
	default:
		return newError("not a function: %s", fn.Type())
	}
}

func extendFunctionEnv(fn *Function, args []Object) *Environment {
	env := NewEnclosedEnvironment(fn.Env)
	for paramIdx, param := range fn.Parameters {
		env.Set(param.Value, args[paramIdx])
	}
	return env
}

func unwrapReturnValue(obj Object) Object {
	if returnValue, ok := obj.(*ReturnValue); ok {
		return returnValue.Value
	}
	return obj
}

func evalStringInflixExpression(operator string, left Object, right Object) Object {
	if operator != "+" {
		return newError("unknown operator: %s %s %s", left.Type(), operator, right.Type())
	}
	leftVal := left.(*String).Value
	rightVal := right.(*String).Value
	return &String{Value: leftVal + rightVal}
}

func evalIndexExpression(left Object, right Object) Object {
	switch {
	case left.Type() == ARRAY_OBJ && right.Type() == INTEGER:
		return evalArrayIndexExpression(left, right)
	case left.Type() == HASH_OBJ:
		return evalHashIndexExpression(left, right)
	default:
		return newError("index operator not supported: %s", left.Type())
	}
}

func evalArrayIndexExpression(array Object, index Object) Object {
	arrayObject := array.(*Array)
	idx := index.(*Integer).Value
	max := int64(len(arrayObject.Elements) - 1)
	if idx >= 0 && idx < max {
		return arrayObject.Elements[idx]
	}
	return NULLOBJ
}

func evalHashLiteral(node *xlang.HashLiteral, env *Environment) Object {
	pairs := make(map[HashKey]HashPair)
	for keyNode, valueNode := range node.Pairs {
		key := Eval(keyNode, env)
		if isError(key) {
			return key
		}
		hashKey, ok := key.(Hashable)
		if !ok {
			return newError("unusable as hash key: %s", key.Type())
		}
		value := Eval(valueNode, env)
		if isError(value) {
			return value
		}
		hashed := hashKey.HashKey()
		pairs[hashed] = HashPair{Key: key, Value: value}
	}
	return &Hash{Pairs: pairs}
}

func evalHashIndexExpression(hash Object, index Object) Object {
	hashObject := hash.(*Hash)
	key, ok := index.(Hashable)
	if !ok {
		return newError("unusalble as hash key: %s", index.Type())
	}
	pair, ok := hashObject.Pairs[key.HashKey()]
	if !ok {
		return NULLOBJ
	}
	return pair.Value
}
