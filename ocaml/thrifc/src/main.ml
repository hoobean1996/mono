open Ast

(** [parse s] parses [s] into an AST. *)
let parse (s : string) : t_program =
  let lexbuf = Lexing.from_string s in
  let ast = Parser.prog Lexer.read lexbuf in
  ast

  (* 
  namespace cpp taco;
  protocol http;
  struct Message { 
    1: i8 age; 
  };
  let p = Interp.Main.parse source;;   
  *)