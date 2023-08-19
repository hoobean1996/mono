package xlangvm

import (
	"fmt"

	"github.com/hebin/awake/pkg/xlanginterpreter"
)

const StackSize = 2048

type VM struct {
	constants    []xlanginterpreter.Object
	instructions Instructions
	stack        []xlanginterpreter.Object
	sp           int // always points to the next value. Top of stack is stack[sp-1]
}

func NewVirtualMachine(bytecode *ByteCode) *VM {
	return &VM{
		instructions: bytecode.Instructions,
		constants:    bytecode.Constants,
		stack:        make([]xlanginterpreter.Object, StackSize),
		sp:           0,
	}
}

func (vm *VM) StackTop() xlanginterpreter.Object {
	if vm.sp == 0 {
		return nil
	}
	return vm.stack[vm.sp-1]
}

func (vm *VM) Run() error {
	for ip := 0; ip < len(vm.instructions); ip++ {
		op := Opcode(vm.instructions[ip])
		switch op {
		case OpConstant:
			constIndex := ReadUint16(vm.instructions[ip+1:])
			ip += 2
			err := vm.push(vm.constants[constIndex])
			if err != nil {
				return err
			}
		case OpJump:
			pos := int(ReadUint16(vm.instructions[ip+1:]))
			ip = pos - 1
		case OpJumpNotTruthy:
			pos := int(ReadUint16(vm.instructions[ip+1 : 1]))
			ip += 2
			condition := vm.pop()
			if !isTruthy(condition) {
				ip = pos - 1
			}
		case OpAdd, OpSub, OpMul, OpDiv:
			err := vm.executeBinaryOperator(op)
			if err != nil {
				return err
			}
		case OpEqual, OpNotEuqal, OpGreaterThan:
			err := vm.executeComparision(op)
			if err != nil {
				return err
			}
		case OpPop:
			vm.pop()
		case OpTrue:
			err := vm.push(True)
			if err != nil {
				return err
			}
		case OpFalse:
			err := vm.push(False)
			if err != nil {
				return err
			}
		case OpBang:
			err := vm.executeBangOperator()
			if err != nil {
				return err
			}
		case OpMinus:
			err := vm.executeMinusOperator()
			if err != nil {
				return err
			}
		}
	}
	return nil
}

func (vm *VM) push(o xlanginterpreter.Object) error {
	if vm.sp >= StackSize {
		return fmt.Errorf("stack overflow")
	}
	vm.stack[vm.sp] = o
	vm.sp++
	return nil
}

func (vm *VM) pop() xlanginterpreter.Object {
	o := vm.stack[vm.sp-1]
	vm.sp--
	return o
}

func (vm *VM) LastPoppedStackElem() xlanginterpreter.Object {
	return vm.stack[vm.sp]
}

func (vm *VM) executeBinaryOperator(op Opcode) error {
	right := vm.pop()
	left := vm.pop()
	leftValue := left.(*xlanginterpreter.Integer).Value
	rightValue := right.(*xlanginterpreter.Integer).Value
	var result int64
	switch op {
	case OpAdd:
		result = leftValue + rightValue
	case OpSub:
		result = leftValue - rightValue
	case OpMul:
		result = leftValue * rightValue
	case OpDiv:
		result = leftValue / rightValue
	}
	return vm.push(&xlanginterpreter.Integer{Value: result})
}

var True = &xlanginterpreter.Boolean{Value: true}
var False = &xlanginterpreter.Boolean{Value: false}

func (vm *VM) executeComparision(op Opcode) error {
	right := vm.pop()
	left := vm.pop()
	if left.Type() == xlanginterpreter.INTEGER && right.Type() == xlanginterpreter.INTEGER {
		return vm.executeIntegerComparsion(op, left, right)
	}
	switch op {
	case OpEqual:
		return vm.push(nativeBoolToBooleanObject(left == right))
	case OpNotEuqal:
		return vm.push(nativeBoolToBooleanObject(left != right))
	default:
		return fmt.Errorf("unknown operator: %d (%s %s)", op, left.Type(), right.Inspect())
	}
}

func (vm *VM) executeIntegerComparsion(op Opcode, left xlanginterpreter.Object, right xlanginterpreter.Object) error {
	leftValue := left.(*xlanginterpreter.Integer).Value
	rightValue := right.(*xlanginterpreter.Integer).Value
	switch op {
	case OpEqual:
		return vm.push(nativeBoolToBooleanObject(rightValue == leftValue))
	case OpNotEuqal:
		return vm.push(nativeBoolToBooleanObject(rightValue != leftValue))
	case OpGreaterThan:
		return vm.push(nativeBoolToBooleanObject(leftValue > rightValue))
	default:
		return fmt.Errorf("unknown operator: %d", op)
	}
}

func nativeBoolToBooleanObject(b bool) *xlanginterpreter.Boolean {
	if b {
		return True
	}
	return False
}

func (vm *VM) executeBangOperator() error {
	operand := vm.pop()
	switch operand {
	case True:
		return vm.push(False)
	case False:
		return vm.push(True)
	default:
		return vm.push(False)
	}
}

func (vm *VM) executeMinusOperator() error {
	operand := vm.pop()
	if operand.Type() != xlanginterpreter.INTEGER {
		return fmt.Errorf("unsupported type for negation: %s", operand.Type())
	}
	value := operand.(*xlanginterpreter.Integer).Value
	return vm.push(&xlanginterpreter.Integer{Value: -value})
}

func isTruthy(obj xlanginterpreter.Object) bool {
	switch obj := obj.(type) {
	case *xlanginterpreter.Boolean:
		return obj.Value
	default:
		return true
	}
}
