package xlang

type TokenType string

type Token struct {
	Type    TokenType
	Literal string
}

const (
	ILLEGAL   = "ILLEGAL"
	EOF       = "EOF"
	IDENT     = "IDENT"
	INT       = "INT"
	ASSIGN    = "="
	EQ        = "=="
	NEQ       = "!="
	PLUS      = "+"
	COMMA     = ","
	SEMICOLON = ";"
	IF        = "IF"
	LPAREN    = "("
	RPAREN    = ")"
	LBRACE    = "{"
	RBRACE    = "}"
	FUNCTION  = "FUNCTION"
	LET       = "LET"
	RETURN    = "RETURN"
	TRUE      = "TRUE"
	FALSE     = "FALSE"
	ELSE      = "ELSE"
	MINUS     = "-"
	BANG      = "!"
	ASTERISK  = "*"
	SLASH     = "/"
	LT        = "<"
	GT        = ">"
	STRING    = "STRING"
	LBRAKET   = "["
	RBRAKET   = "]"
	COLON     = ":"
)
