package main

import (
	"fmt"
	"os"
	"os/user"

	"liquid.io/dsl/awake/pkg/xlangrepl"
)

func main() {
	user, err := user.Current()
	if err != nil {
		panic(err)
	}
	fmt.Printf("Hello %s! This is the Xlang programming language!\n", user.Username)
	fmt.Println("Feel free to type in commands")
	xlangrepl.Start(os.Stdin, os.Stdout)
}
