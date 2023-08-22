package xlangvm

import (
	"fmt"
	"testing"

	"liquid.io/dsl/awake/pkg/xlanginterpreter"
)

type vmTestCase struct {
	input    string
	expected interface{}
}

func runVmTests(t *testing.T, tests []vmTestCase) {
	t.Helper()
	for _, tt := range tests {
		program := parse(tt.input)
		comp := NewCompiler()
		err := comp.Compile(program)
		if err != nil {
			t.Fatalf("compiler error: %s", err)
		}
		vm := NewVirtualMachine(comp.Bytecode())
		err = vm.Run()
		if err != nil {
			t.Fatalf("vm error: %s", err)
		}
		stackElem := vm.LastPoppedStackElem()
		testExpectedObject(t, tt.expected, stackElem)
	}
}

func testExpectedObject(t *testing.T, expected interface{}, actual xlanginterpreter.Object) {
	t.Helper()
	switch expected := expected.(type) {
	case int:
		err := testIntegerObject(int64(expected), actual)
		if err != nil {
			t.Errorf("testIntegerObject failed: %s", err)
		}
	case bool:
		err := testBooleanObject(bool(expected), actual)
		if err != nil {
			t.Errorf("testBooleanObject failed: %s", err)
		}
	}
}

func TestIntegerArithmeticVM(t *testing.T) {
	tests := []vmTestCase{
		{"1", 1},
		{"2", 2},
		{"1+2", 3},
		{"1+3", 4},
		{"1-2", -1},
		{"1*2", 2},
		{"4/2", 2},
		{"5 + 5 * 2", 15},
		{"-5", -5},
		{"-10", -10},
		{"-50 + 100 + -50", 0},
	}
	runVmTests(t, tests)
}

func TestBooleanExpression(t *testing.T) {
	tests := []vmTestCase{
		{"true", true},
		{"false", false},
		{"1 < 2", true},
		{"1 > 2", false},
		{"1 == 2", false},
		{"true == true", true},
		{"!false", true},
		{"!true", false},
	}
	runVmTests(t, tests)
}

func testBooleanObject(expected bool, actual xlanginterpreter.Object) error {
	result, ok := actual.(*xlanginterpreter.Boolean)
	if !ok {
		return fmt.Errorf("object is not a Boolean. got=%T (%+v)", actual, actual)
	}
	if result.Value != expected {
		return fmt.Errorf("object has wrong value. got=%t, want=%t", result.Value, expected)
	}
	return nil
}

func TstConditions(t *testing.T) {
	tests := []vmTestCase{
		{"if (true) {10}", 10},
		{"if (true) {10} else {20}", 10},
		{"if (false){10} else{20}", 20},
	}
	runVmTests(t, tests)
}
