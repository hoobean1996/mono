package xlangrepl

import (
	"bufio"
	"fmt"
	"io"
	"strings"

	"liquid.io/dsl/awake/pkg/xlang"
	"liquid.io/dsl/awake/pkg/xlanginterpreter"
)

const PROMT = ">>"

func Start(in io.Reader, out io.Writer) {
	scanner := bufio.NewScanner(in)
	env := xlanginterpreter.NewEnvironmenet()
	for {
		fmt.Println(PROMT)
		scanned := scanner.Scan()
		if !scanned {
			return
		}
		line := scanner.Text()
		l := xlang.NewLexer(line)
		p := xlang.NewParser(l)
		program := p.Parse()
		if len(p.Errors()) != 0 {
			io.WriteString(out, strings.Join(p.Errors(), ","))
		}
		evaluated := xlanginterpreter.Eval(program, env)
		if evaluated != nil {
			io.WriteString(out, string(evaluated.Type()))
			io.WriteString(out, ",")
			io.WriteString(out, evaluated.Inspect())
			io.WriteString(out, "\n")
		}
	}
}
