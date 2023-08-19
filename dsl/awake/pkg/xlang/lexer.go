package xlang

type Lexer struct {
	input        string
	position     int
	readPosition int
	ch           byte
}

func NewLexer(input string) *Lexer {
	l := &Lexer{input: input}
	l.readChar()
	return l
}

func (l *Lexer) NextToken() Token {
	var tok Token
	l.skipWhitespace()
	switch l.ch {
	case '=':
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = Token{EQ, string(ch) + string(l.ch)}
		} else {
			tok = Token{ASSIGN, string(l.ch)}
		}
	case ';':
		tok = Token{SEMICOLON, string(l.ch)}
	case ':':
		tok = Token{COLON, string(l.ch)}
	case '"':
		tok = Token{STRING, l.readString()}
	case '`':

	case '(':
		tok = Token{LPAREN, string(l.ch)}
	case ')':
		tok = Token{RPAREN, string(l.ch)}
	case ',':
		tok = Token{COMMA, string(l.ch)}
	case '+':
		tok = Token{PLUS, string(l.ch)}
	case '{':
		tok = Token{LBRACE, string(l.ch)}
	case '}':
		tok = Token{RBRACE, string(l.ch)}
	case '[':
		tok = Token{LBRAKET, string(l.ch)}
	case ']':
		tok = Token{RBRAKET, string(l.ch)}
	case '-':
		tok = Token{MINUS, string(l.ch)}
	case '/':
		tok = Token{SLASH, string(l.ch)}
	case '<':
		tok = Token{LT, string(l.ch)}
	case '>':
		tok = Token{GT, string(l.ch)}
	case '!':
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = Token{NEQ, string(ch) + string(l.ch)}
		} else {
			tok = Token{BANG, string(l.ch)}

		}
	case '*':
		tok = Token{ASTERISK, string(l.ch)}
	case 0:
		tok = Token{EOF, ""}
	default:
		if isLetter(l.ch) {
			tok.Literal = l.readIdentifier()
			tok.Type = lookUpIdent(tok.Literal)
			return tok
		} else if isDigit(l.ch) {
			tok.Literal = l.readNumber()
			tok.Type = INT
			return tok
		} else {
			tok = Token{ILLEGAL, string(l.ch)}
		}
	}
	l.readChar()
	return tok
}

func (l *Lexer) readChar() {
	if l.readPosition >= len(l.input) {
		l.ch = 0
	} else {
		l.ch = l.input[l.readPosition]
	}
	l.position = l.readPosition
	l.readPosition += 1
}

func (l *Lexer) peekChar() byte {
	if l.readPosition >= len(l.input) {
		return 0
	}
	return l.input[l.readPosition]
}

func (l *Lexer) readIdentifier() string {
	position := l.position
	for isLetter(l.ch) {
		l.readChar()
	}
	return l.input[position:l.position]
}

func isLetter(ch byte) bool {
	return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_'
}

var keywords = map[string]TokenType{
	"fn":     FUNCTION,
	"let":    LET,
	"true":   TRUE,
	"false":  FALSE,
	"if":     IF,
	"else":   ELSE,
	"return": RETURN,
}

func lookUpIdent(ident string) TokenType {
	if tok, ok := keywords[ident]; ok {
		return tok
	}
	return IDENT
}

func (l *Lexer) skipWhitespace() {
	for l.ch == ' ' || l.ch == '\t' || l.ch == '\n' || l.ch == '\r' {
		l.readChar()
	}
}

func isDigit(ch byte) bool {
	return '0' <= ch && ch <= '9'
}

func (l *Lexer) readNumber() string {
	position := l.position
	for isDigit(l.ch) {
		l.readChar()
	}
	return l.input[position:l.position]
}

func (l *Lexer) readString() string {
	position := l.position + 1
	for {
		l.readChar()
		if l.ch == '"' || l.ch == 0 {
			break
		}
	}
	return l.input[position:l.position]
}
