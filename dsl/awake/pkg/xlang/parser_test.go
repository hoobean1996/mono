package xlang

import (
	"fmt"
	"testing"
)

func TestParseLetStatement(t *testing.T) {
	tests := []struct {
		input              string
		expectedIdentifier string
		expectedValue      interface{}
	}{
		{"let x = 5;", "x", 5},
		{"let y = true;", "y", true},
		{"let foobar = y;", "foobar", "y"},
	}
	for _, tt := range tests {
		l := NewLexer(tt.input)
		p := NewParser(l)
		program := p.Parse()
		checkParserErrors(t, p)
		if program == nil {
			t.Fatalf("Parse() returned nil")
		}
		if len(program.Statements) != 1 {
			t.Fatalf("program.Statements does not contain 3 statements. got=%d", len(program.Statements))
		}
	}
}

func TestReturnStatement(t *testing.T) {
	input := `
	return 5;
	return 10;
	return 99322;`
	l := NewLexer(input)
	p := NewParser(l)
	program := p.Parse()
	checkParserErrors(t, p)
	if len(program.Statements) != 3 {
		t.Fatalf("program.Statements does not contain 3 statements. got=%d", len(program.Statements))
	}
	for _, stmt := range program.Statements {
		returnStmt, ok := stmt.(*ReturnStatement)
		if !ok {
			t.Errorf("stmt not *ReturnStatement. got=%T", stmt)
			continue
		}
		if returnStmt.TokenLiteral() != "return" {
			t.Errorf("returnStmt.TokenLiteral not 'return', got=%q", returnStmt.TokenLiteral())
		}
	}
}

func checkParserErrors(t *testing.T, p *Parser) {
	errors := p.Errors()
	if len(errors) == 0 {
		return
	}
	t.Errorf("parser has %d errors", len(errors))
	for _, msg := range errors {
		t.Errorf("parser error: %q", msg)
	}
	t.FailNow()
}

func TestStringfy(t *testing.T) {
	program := &Program{
		Statements: []Statement{
			&LetStatement{
				Token: Token{LET, "let"},
				Name: &Identifier{
					Token: Token{IDENT, "myvar"},
					Value: "myvar",
				},
				Value: &Identifier{
					Token: Token{IDENT, "myvar2"},
					Value: "myvar2",
				},
			},
		},
	}
	if program.String() != "let myvar = myvar2;" {
		t.Errorf("program.String() wrong. got=%q", program.String())
	}
}

func TestParseIdenfierExpression(t *testing.T) {
	input := "foobar;"
	l := NewLexer(input)
	p := NewParser(l)
	program := p.Parse()
	checkParserErrors(t, p)
	if len(program.Statements) != 1 {
		t.Fatalf("program has not enough statements. got=%d", len(program.Statements))
	}
	stmt, ok := program.Statements[0].(*ExpressionStatement)
	if !ok {
		t.Fatalf("program.Statements[0] is not ExpressionStatement. got=%T", program.Statements[0])
	}
	ident, ok := stmt.Expression.(*Identifier)
	if !ok {
		t.Fatalf("exp not *Identifier. got=%T", stmt.Expression)
	}
	if ident.Value != "foobar" {
		t.Errorf("ident.Value not %s. got=%s", "foobar", ident.Value)
	}
	if ident.TokenLiteral() != "foobar" {
		t.Errorf("ident.TokenLiteral not %s. got=%s", "foobar", ident.TokenLiteral())
	}
}

func TestParseIntegerLiteral(t *testing.T) {
	input := "5;"
	l := NewLexer(input)
	p := NewParser(l)
	program := p.Parse()
	checkParserErrors(t, p)
	if len(program.Statements) != 1 {
		t.Fatalf("program has not enough statements. got=%d", len(program.Statements))
	}
	stmt, ok := program.Statements[0].(*ExpressionStatement)
	if !ok {
		t.Fatalf("program.Statements[0] is not Expression. got=%T", program.Statements[0])
	}
	literal, ok := stmt.Expression.(*IntegerLiteral)
	if !ok {
		t.Fatalf("exp not *IntegerLiteral. got=%T", stmt.Expression)
	}
	if literal.Value != 5 {
		t.Errorf("literal.Value not %d. got=%d", 5, literal.Value)
	}
	if literal.TokenLiteral() != "5" {
		t.Errorf("literal.TokenLiteral not %s. got=%s", "5", literal.TokenLiteral())
	}
}

func TestParsePrefixExpression(t *testing.T) {
	tests := []struct {
		input        string
		operator     string
		integerValue int64
	}{
		{"!5", "!", 5},
		{"-15", "-", 15},
	}
	for _, tt := range tests {
		l := NewLexer(tt.input)
		p := NewParser(l)
		program := p.Parse()
		checkParserErrors(t, p)
		if len(program.Statements) != 1 {
			t.Fatalf("program.Statements does not contain %d statement. got=%d\n", 1, len(program.Statements))
		}
		stmt, ok := program.Statements[0].(*ExpressionStatement)
		if !ok {
			t.Fatalf("program.Statements[0] is not ExpressionStatement. got=%T", program.Statements[0])
		}
		exp, ok := stmt.Expression.(*PrefixExpression)
		if !ok {
			t.Fatalf("stmt is not PreflixExpression. got=%T", stmt.Expression)
		}
		if exp.Operator != tt.operator {
			t.Fatalf("exp.Operator is not %s. got=%s", tt.operator, exp.Operator)
		}
		if !testIntegerLiteral(t, exp.Right, tt.integerValue) {
			return
		}
	}
}

func testIntegerLiteral(t *testing.T, il Expression, value int64) bool {
	integ, ok := il.(*IntegerLiteral)
	if !ok {
		t.Errorf("il not *IntegerLiteral. got=%T", il)
	}
	if integ.Value != value {
		t.Errorf("integ.Value not %d. got=%d", value, integ.Value)
		return false
	}
	if integ.TokenLiteral() != fmt.Sprintf("%d", value) {
		t.Errorf("integ.TokenLiteral not %d. got=%s", value, integ.TokenLiteral())
		return false
	}
	return true
}

func TestParseInflixExpression(t *testing.T) {
	tests := []struct {
		input      string
		leftValue  int64
		operator   string
		rightValue int64
	}{
		{"5+5;", 5, "+", 5},
		{"5-5;", 5, "-", 5},
		{"5*5;", 5, "*", 5},
		{"5/5", 5, "/", 5},
		{"5>5", 5, ">", 5},
		{"5<5", 5, "<", 5},
		{"5==5", 5, "==", 5},
		{"5!=5", 5, "!=", 5},
	}
	for _, tt := range tests {
		l := NewLexer(tt.input)
		p := NewParser(l)
		program := p.Parse()
		checkParserErrors(t, p)
		if len(program.Statements) != 1 {
			t.Fatalf("program.Statements does not contain %d statements. got=%d\n", 1, len(program.Statements))
		}
		stmt, ok := program.Statements[0].(*ExpressionStatement)
		if !ok {
			t.Fatalf("program.Statement[0] is not ExpressionStatement. got=%T", program.Statements[0])
		}
		exp, ok := stmt.Expression.(*InflixExpression)
		if !ok {
			t.Fatalf("exp is not InflixExpression. got=%T", stmt.Expression)
		}
		if !testIntegerLiteral(t, exp.Left, tt.leftValue) {
			return
		}
		if exp.Operator != tt.operator {
			t.Fatalf("exp.Operator is not %s. got=%s", tt.operator, exp.Operator)
		}
		if !testIntegerLiteral(t, exp.Right, tt.rightValue) {
			return
		}
	}
}

func TestParseOperatorPrecende(t *testing.T) {
	tests := []struct {
		input    string
		expected string
	}{
		{"-a*b", "((-a) * b)"},
		{"!-a", "(!(-a))"},
		{"a+b+c", "((a + b) + c)"},
		{"a+b-c", "((a + b) - c)"},
		{"a*b*c", "((a * b) * c)"},
		{"a*b/c", "((a * b) / c)"},
		{"a+b/c", "(a + (b / c))"},
		{"a + b * c + d / e -f", "(((a + (b * c)) + (d / e)) - f)"},
		{"true", "true"},
		{"false", "false"},
		{"3 > 5 == false", "((3 > 5) == false)"},
		{"1+(2+3)+4", "((1 + (2 + 3)) + 4)"},
		{"a+add(b*c)+d", "((a + add((b * c))) + d)"},
		{"add(a, b, 1, 2*3, 4+5, add(6, 7 * 8))", "add(a, b, 1, (2 * 3), (4 + 5), add(6, (7 * 8)))"},
		{"a * [1, 2, 3, 4][b*c]*d", "((a * ([1, 2, 3, 4][(b * c)]) * d)"},
	}
	for _, tt := range tests {
		l := NewLexer(tt.input)
		p := NewParser(l)
		program := p.Parse()
		actual := program.String()
		if actual != tt.expected {
			t.Errorf("expected=%q, got=%q", tt.expected, actual)
		}
	}
}

func testIdentifier(t *testing.T, exp Expression, value string) bool {
	ident, ok := exp.(*Identifier)
	if !ok {
		t.Errorf("exp not *Identifier. got=%t", exp)
		return false
	}
	if ident.Value != value {
		t.Errorf("ident.Value not %s. got=%s", value, ident.Value)
		return false
	}
	if ident.TokenLiteral() != value {
		t.Errorf("ident.TokenLiteral not %s. got=%s", value, ident.TokenLiteral())
		return false
	}
	return true
}

func testLiteralExpression(
	t *testing.T,
	exp Expression,
	expected interface{},
) bool {
	switch v := expected.(type) {
	case int:
		return testIntegerLiteral(t, exp, int64(v))
	case int64:
		return testIntegerLiteral(t, exp, v)
	case string:
		return testIdentifier(t, exp, v)
	case bool:
		return testBooleanLiteral(t, exp, v)
	}
	t.Errorf("type of exp not handled. got=%T", exp)
	return false
}

func testInflixExpression(t *testing.T, exp Expression, left interface{}, operator string, right interface{}) bool {
	opExp, ok := exp.(*InflixExpression)
	if !ok {
		t.Errorf("exp is not OperatorExpression. got=%T(%s)", exp, exp)
		return false
	}
	if !testLiteralExpression(t, opExp.Left, left) {
		return false
	}
	if opExp.Operator != operator {
		t.Errorf("exp.Operator is not %s. got=%q", operator, opExp.Operator)
		return false
	}
	if !testLiteralExpression(t, opExp.Right, right) {
		return false
	}
	return true
}

func testBooleanLiteral(t *testing.T, exp Expression, value bool) bool {
	bo, ok := exp.(*Boolean)
	if !ok {
		t.Errorf("exp not *Boolean. got=%T", exp)
		return false
	}
	if bo.Value != value {
		t.Errorf("bo.Value not %t. got=%t", value, bo.Value)
		return false
	}
	if bo.TokenLiteral() != fmt.Sprintf("%t", value) {
		t.Errorf("bo.TokenLiteral not %t. got=%s", value, bo.TokenLiteral())
		return false
	}
	return true
}

func TestIfExpression(t *testing.T) {
	input := `if (x < y) { x }`
	l := NewLexer(input)
	p := NewParser(l)
	program := p.Parse()
	checkParserErrors(t, p)
	if len(program.Statements) != 1 {
		t.Fatalf("program.Body does not contain %d statements. got=%d\n", 1, len(program.Statements))
	}
	stmt, ok := program.Statements[0].(*ExpressionStatement)
	if !ok {
		t.Fatalf("program.Statements[0] is not ExpressionStatement. got=%T", program.Statements[0])
	}
	exp, ok := stmt.Expression.(*IfExpression)
	if !ok {
		t.Fatalf("stmt.Expression is not IfExpreesion. got=%T", stmt.Expression)
	}
	if !testInflixExpression(t, exp.Condition, "x", "<", "y") {
		return
	}
	if len(exp.Consequence.Statements) != 1 {
		t.Errorf("consequence is not 1 statements. got=%d\n", len(exp.Consequence.Statements))
	}
	consequnce, ok := exp.Consequence.Statements[0].(*ExpressionStatement)
	if !ok {
		t.Fatalf("Statements[0] is not ExpressionStatement. got=%T", exp.Consequence.Statements[0])
	}
	if !testIdentifier(t, consequnce.Expression, "x") {
		return
	}
	if exp.Alternative != nil {
		t.Errorf("exp.Alternative.Statements was not nil. got=%+v", exp.Alternative)
	}
}

func TestFunctionLiteral(t *testing.T) {
	input := `fn(x, y) {x + y;}`
	l := NewLexer(input)
	p := NewParser(l)
	program := p.Parse()
	checkParserErrors(t, p)
	if len(program.Statements) != 1 {
		t.Fatalf("program.Body does not contain %d statements. got=%d\n", 1, len(program.Statements))
	}
	stmt, ok := program.Statements[0].(*ExpressionStatement)
	if !ok {
		t.Fatalf("program.Statements[0] is not ExpressionStatement. got=%T", program.Statements[0])
	}
	function, ok := stmt.Expression.(*FunctionLiteral)
	if !ok {
		t.Fatalf("stmt.Expression is not FunctionLiteral. got=%T", stmt.Expression)
	}
	if len(function.Parameters) != 2 {
		t.Fatalf("function literal parameters wrong. want 2, got=%d\n", len(function.Parameters))
	}
	testLiteralExpression(t, function.Parameters[0], "x")
	testLiteralExpression(t, function.Parameters[1], "y")
	if len(function.Body.Statements) != 1 {
		t.Fatalf("function.Body.Statements has not 1 statements. got=%d\n", len(function.Body.Statements))
	}
	bodyStmt, ok := function.Body.Statements[0].(*ExpressionStatement)
	if !ok {
		t.Fatalf("function body stmt is not ExpressioinStatement. got=%T", function.Body.Statements[0])
	}
	testInflixExpression(t, bodyStmt.Expression, "x", "+", "y")
}

func TestFunctionParameter(t *testing.T) {
	tests := []struct {
		input          string
		expectedParams []string
	}{
		{input: "fn(){};", expectedParams: []string{}},
		{input: "fn(x){};", expectedParams: []string{"x"}},
		{input: "fn(x,y,z){};", expectedParams: []string{"x", "y", "z"}},
	}
	for _, tt := range tests {
		l := NewLexer(tt.input)
		p := NewParser(l)
		program := p.Parse()
		checkParserErrors(t, p)
		stmt := program.Statements[0].(*ExpressionStatement)
		function := stmt.Expression.(*FunctionLiteral)
		if len(function.Parameters) != len(tt.expectedParams) {
			t.Errorf("length parameter wrong. want %d, got=%d\n", len(tt.expectedParams), len(function.Parameters))
		}
		for i, ident := range tt.expectedParams {
			testLiteralExpression(t, function.Parameters[i], ident)
		}
	}
}

func TestCallExpression(t *testing.T) {
	input := "add(1,2*3,4+5);"
	l := NewLexer(input)
	p := NewParser(l)
	program := p.Parse()
	checkParserErrors(t, p)
	if len(program.Statements) != 1 {
		t.Fatalf("program.Statements does not contain %d statements. got=%d\n", 1, len(program.Statements))
	}
	stmt, ok := program.Statements[0].(*ExpressionStatement)
	if !ok {
		t.Fatalf("stmt is not ExpressionStatement. got=%T", program.Statements[0])
	}
	exp, ok := stmt.Expression.(*CallExpression)
	if !ok {
		t.Fatalf("stmt.Expression is not CallExpression. got=%T", stmt.Expression)
	}
	if !testIdentifier(t, exp.Function, "add") {
		return
	}
	if len(exp.Arguments) != 3 {
		t.Fatalf("wrong length of arguments. got=%d", len(exp.Arguments))
	}
	testLiteralExpression(t, exp.Arguments[0], 1)
	testInflixExpression(t, exp.Arguments[1], 2, "*", 3)
	testInflixExpression(t, exp.Arguments[2], 4, "+", 5)
}

func TestStringLiteralExpression(t *testing.T) {
	input := `"hello world"`
	l := NewLexer(input)
	p := NewParser(l)
	program := p.Parse()
	checkParserErrors(t, p)
	stmt := program.Statements[0].(*ExpressionStatement)
	literal, ok := stmt.Expression.(*StringLiteral)
	if !ok {
		t.Fatalf("exp not *StringLiteral. got=%T", stmt.Expression)
	}
	if literal.Value != "hello world" {
		t.Errorf("literal.Value not %q. got=%q", "hello world", literal.Value)
	}
}

func TestParseArrayLiteral(t *testing.T) {
	input := `[1, 2*2, 3 +3]`
	l := NewLexer(input)
	p := NewParser(l)
	program := p.Parse()
	checkParserErrors(t, p)
	stmt, ok := program.Statements[0].(*ExpressionStatement)
	if !ok {
		t.Fatalf("exp not ExpressionStatement. got=%T", program.Statements[0])
	}
	array, ok := stmt.Expression.(*ArrayLiteral)
	if !ok {
		t.Fatalf("exp not ArrayLiteral. got=%T", stmt.Expression)
	}
	if len(array.Elements) != 3 {
		t.Fatalf("len(array.Elements) not 3. got=%d", len(array.Elements))
	}
	testIntegerLiteral(t, array.Elements[0], 1)
	testInflixExpression(t, array.Elements[1], 2, "*", 2)
	testInflixExpression(t, array.Elements[2], 3, "+", 3)
}

func TestParseIndexExpression(t *testing.T) {
	input := `myArray[1 + 1]`
	l := NewLexer(input)
	p := NewParser(l)
	program := p.Parse()
	checkParserErrors(t, p)
	stmt, _ := program.Statements[0].(*ExpressionStatement)
	indexExp, ok := stmt.Expression.(*IndexExpression)
	if !ok {
		t.Errorf("exp not *IndexExpression. got=%T", stmt.Expression)
	}
	if !testIdentifier(t, indexExp.Left, "myArray") {
		return
	}
	if !testInflixExpression(t, indexExp.Index, 1, "+", 1) {
		return
	}
}

func TestParsingEmptyHashLiteral(t *testing.T) {
	input := "{}"
	l := NewLexer(input)
	p := NewParser(l)
	program := p.Parse()
	checkParserErrors(t, p)
	stmt := program.Statements[0].(*ExpressionStatement)
	hash, ok := stmt.Expression.(*HashLiteral)
	if !ok {
		t.Fatalf("exp is not HashLiteral, got=%T", stmt.Expression)
	}
	if len(hash.Pairs) != 0 {
		t.Fatalf("hash.Pairs has wrong length. got=%d", len(hash.Pairs))
	}
}

func TestParsingHashLiteral(t *testing.T) {
	input := `{"one": 1, "two": 2, "three": 3}`
	l := NewLexer(input)
	p := NewParser(l)
	program := p.Parse()
	checkParserErrors(t, p)
	stmt := program.Statements[0].(*ExpressionStatement)
	hash, ok := stmt.Expression.(*HashLiteral)
	if !ok {
		t.Fatalf("exp is not HashLiteral. got=%T", stmt.Expression)
	}
	if len(hash.Pairs) != 3 {
		t.Errorf("hash.Pairs has wrong leng. got=%d", len(hash.Pairs))
	}
	expected := map[string]int64{
		"one":   1,
		"two":   2,
		"three": 3,
	}
	for key, value := range hash.Pairs {
		literal, ok := key.(*StringLiteral)
		if !ok {
			t.Errorf("key is not StringLiteral. got=%T", key)
		}
		expectedValue := expected[literal.String()]
		testIntegerLiteral(t, value, expectedValue)
	}
}
