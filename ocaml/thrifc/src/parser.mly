%{
open Ast
%}

// Token declarations
%token <string> ID
%token <int> NUMBER

%token EOF
%token NAMESPACE
%token PROTOCOL
%token STRUCT
%token LPAREN
%token RPAREN
%token SEMICOLON
%token STRING
%token BOOL
%token I8
%token I16
%token I32
%token I64
%token COLON


// Start parsing a Thrift program
%start <Ast.t_program> prog

%%

prog:
  |ns = namespace; pt = protocol; decl_list = decls; EOF { {namespace=ns; protocol=pt; decls=decl_list;} }
  ;

decls:
  | d = decl; ds = decls { d :: ds }
  | { [] }
  ;

decl:
  | STRUCT; name = ID; LPAREN; field_list = fields; RPAREN; SEMICOLON { Struct {struct_name=name; struct_fields=field_list;}}
  ;

field_type:
  | STRING { type_of_string "string"}
  | BOOL { type_of_string "bool" }
  | I8 { type_of_string "i8"}
  | I16 { type_of_string "i16"}
  | I32 { type_of_string "i32"}
  | I64 { type_of_string "i64"}
  | { TUnknown }

field:
  | NUMBER; COLON; t = field_type; name = ID;  SEMICOLON { {field_name=name; field_type=t; field_optional=false;}}
  ;

fields:
  | f = field; fs = fields { f :: fs }
  | { [] }
  ;

namespace:
  | NAMESPACE; language = ID; name = ID; SEMICOLON { {language=language; name=name;} }
  ;

protocol:
  | PROTOCOL; protocol = ID; SEMICOLON { {name=protocol;} }
  ;