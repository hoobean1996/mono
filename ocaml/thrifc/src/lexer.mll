{
open Parser
}

(* Use regex to define tokens *)
let white = [' ' '\t']+
let digit = ['0'-'9']
let int = '-'? digit+
let letter = ['a'-'z' 'A'-'Z']
let id = letter+

(* rule and parse are keyworks *)
(* read is name *)
(* when a regular expression matches, then lexer produces the token specified by its action *)
rule read =
  parse
  | white { read lexbuf }
  | "namespace" { NAMESPACE }
  | "protocol" { PROTOCOL }
  | "struct" { STRUCT }
  | ";" { SEMICOLON }
  | ":" { COLON }
  | "{" { LPAREN }
  | "}" { RPAREN }
  | "string" { STRING }
  | "bool" { BOOL }
  | "i8" { I8 }
  | "i16" { I16 }
  | "i32" { I32 }
  | "i64" { I64 }
  | id { ID (Lexing.lexeme lexbuf) }
  | digit { NUMBER (int_of_string (Lexing.lexeme lexbuf)) }
  | eof { EOF }