package xlangvm

import (
	"fmt"
	"testing"

	"liquid.io/dsl/awake/pkg/xlang"
	"liquid.io/dsl/awake/pkg/xlanginterpreter"
)

type compilerTestCase struct {
	input                string
	expectedConstants    []interface{}
	expectedInstructions []Instructions
}

func TestIntegerArithmetic(t *testing.T) {
	tests := []compilerTestCase{
		{
			input:             "1 + 2",
			expectedConstants: []interface{}{1, 2},
			expectedInstructions: []Instructions{
				Make(OpConstant, 0),
				Make(OpConstant, 1),
				Make(OpAdd),
				Make(OpPop),
			},
		},
		{
			input:             "1;2",
			expectedConstants: []interface{}{1, 2},
			expectedInstructions: []Instructions{
				Make(OpConstant, 0),
				Make(OpPop),
				Make(OpConstant, 1),
				Make(OpPop),
			},
		},
		{
			input:             "1-2",
			expectedConstants: []interface{}{1, 2},
			expectedInstructions: []Instructions{
				Make(OpConstant, 0),
				Make(OpConstant, 1),
				Make(OpSub),
				Make(OpPop),
			},
		},
		{
			input:             "1*2",
			expectedConstants: []interface{}{1, 2},
			expectedInstructions: []Instructions{
				Make(OpConstant, 0),
				Make(OpConstant, 1),
				Make(OpMul),
				Make(OpPop),
			},
		},
		{
			input:             "2 / 1",
			expectedConstants: []interface{}{2, 1},
			expectedInstructions: []Instructions{
				Make(OpConstant, 0),
				Make(OpConstant, 1),
				Make(OpDiv),
				Make(OpPop),
			},
		},
		{
			input:             "-1",
			expectedConstants: []interface{}{1},
			expectedInstructions: []Instructions{
				Make(OpConstant, 0),
				Make(OpMinus),
				Make(OpPop),
			},
		},
	}
	runCompilerTests(t, tests)
}

func runCompilerTests(t *testing.T, tests []compilerTestCase) {
	t.Helper()
	for _, tt := range tests {
		program := parse(tt.input)
		compiler := NewCompiler()
		err := compiler.Compile(program)
		if err != nil {
			t.Fatalf("compiler error: %s", err)
		}
		bytecode := compiler.Bytecode()
		err = testInstructions(tt.expectedInstructions, bytecode.Instructions)
		if err != nil {
			t.Fatalf("testInstructions failed: %s", err)
		}
		err = testConstants(t, tt.expectedConstants, bytecode.Constants)
		if err != nil {
			t.Fatalf("testConstants failed: %s", err)
		}
	}
}

func parse(input string) *xlang.Program {
	l := xlang.NewLexer(input)
	p := xlang.NewParser(l)
	return p.Parse()
}

func testInstructions(
	expected []Instructions,
	actual Instructions,
) error {
	concatted := concatInstructions(expected)
	if len(actual) != len(concatted) {
		return fmt.Errorf("wrong instructions length.\n want=%q, got=%q", concatted, actual)
	}
	for i, ins := range concatted {
		if actual[i] != ins {
			return fmt.Errorf("wrong instruction at %d. \n want=%q, got=%q", i, concatted, actual)
		}
	}
	return nil
}

func concatInstructions(s []Instructions) Instructions {
	out := Instructions{}
	for _, ins := range s {
		out = append(out, ins...)
	}
	return out
}

func testConstants(
	t *testing.T,
	expected []interface{},
	actual []xlanginterpreter.Object,
) error {
	if len(expected) != len(actual) {
		return fmt.Errorf("wrong number of constants. got=%d, want=%d", len(actual), len(expected))
	}
	for i, constant := range expected {
		switch constant := constant.(type) {
		case int:
			err := testIntegerObject(int64(constant), actual[i])
			if err != nil {
				return fmt.Errorf("constant %d - testIntegerObject failed: %s", i, err)
			}
		}
	}
	return nil
}

func testIntegerObject(expected int64, actual xlanginterpreter.Object) error {
	result, ok := actual.(*xlanginterpreter.Integer)
	if !ok {
		return fmt.Errorf("object is not Integer. got=%T (%+v)", actual, actual)
	}
	if result.Value != expected {
		return fmt.Errorf("object has wrong value. got=%d, want=%d", result.Value, expected)
	}
	return nil
}

func TestInstructionsString(t *testing.T) {
	instructions := []Instructions{
		Make(OpConstant, 1),
		Make(OpConstant, 2),
		Make(OpConstant, 65535),
	}
	expected := `0000 OpConstant 1
0003 OpConstant 2
0006 OpConstant 65535
`

	concatted := Instructions{}
	for _, ins := range instructions {
		concatted = append(concatted, ins...)
	}
	t.Log("concatted", concatted, len(concatted))

	if concatted.String() != expected {
		t.Errorf("instructions wrongly formatted. want=%q, got=%q", expected, concatted.String())
	}
}

func TestReadOperands(t *testing.T) {
	tests := []struct {
		op        Opcode
		operands  []int
		bytesRead int
	}{
		{OpConstant, []int{65535}, 2},
	}
	for _, tt := range tests {
		instruction := Make(tt.op, tt.operands...)
		def, err := LookUp(byte(tt.op))
		if err != nil {
			t.Fatalf("definition not found: %q\n", err)
		}
		operandsRead, n := ReadOperands(def, instruction[1:])
		if n != tt.bytesRead {
			t.Fatalf("n wrong. \n want=%d, \n got=%d", tt.bytesRead, n)
		}
		for i, want := range tt.operands {
			if operandsRead[i] != want {
				t.Errorf("operand wrong. want=%d, got=%d", want, operandsRead[i])
			}
		}
	}
}

func TestBooleanExpressions(t *testing.T) {
	tests := []compilerTestCase{
		{
			input:             "true",
			expectedConstants: []interface{}{},
			expectedInstructions: []Instructions{
				Make(OpTrue),
				Make(OpPop),
			},
		},
		{
			input:             "false",
			expectedConstants: []interface{}{},
			expectedInstructions: []Instructions{
				Make(OpFalse),
				Make(OpPop),
			},
		},
		{
			input:             "1 > 2",
			expectedConstants: []interface{}{1, 2},
			expectedInstructions: []Instructions{
				Make(OpConstant, 0),
				Make(OpConstant, 1),
				Make(OpGreaterThan),
				Make(OpPop),
			},
		},
		{
			input:             "1 < 2",
			expectedConstants: []interface{}{2, 1},
			expectedInstructions: []Instructions{
				Make(OpConstant, 0),
				Make(OpConstant, 1),
				Make(OpGreaterThan),
				Make(OpPop),
			},
		},
		{
			input:             "1 == 2",
			expectedConstants: []interface{}{1, 2},
			expectedInstructions: []Instructions{
				Make(OpConstant, 0),
				Make(OpConstant, 1),
				Make(OpEqual),
				Make(OpPop),
			},
		},
		{
			input:             "1 != 2",
			expectedConstants: []interface{}{1, 2},
			expectedInstructions: []Instructions{
				Make(OpConstant, 0),
				Make(OpConstant, 1),
				Make(OpNotEuqal),
				Make(OpPop),
			},
		},
		{
			input:             "!false",
			expectedConstants: []interface{}{},
			expectedInstructions: []Instructions{
				Make(OpFalse),
				Make(OpBang),
				Make(OpPop),
			},
		},
	}
	runCompilerTests(t, tests)
}

func TestConditions(t *testing.T) {
	tests := []compilerTestCase{
		{
			input:             `if (true) {10} else {20}; 3333;`,
			expectedConstants: []interface{}{10, 20, 3333},
			expectedInstructions: []Instructions{
				Make(OpTrue),
				Make(OpJumpNotTruthy, 10),
				Make(OpConstant, 0),
				Make(OpJump, 13),
				Make(OpConstant, 1),
				Make(OpPop),
				Make(OpConstant, 2),
				Make(OpPop),
			},
		},
	}
	runCompilerTests(t, tests)
}
