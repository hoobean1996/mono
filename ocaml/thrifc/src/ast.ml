type t_type = 
  | TString
  | TBool 
  | TI8
  | TI16
  | TI32
  | TI64
  | TUnknown

let type_of_string s = 
  match s with 
  | "string" -> TString
  | "bool" -> TBool
  | "i8" -> TI8
  | "i16" -> TI16
  | "i32" -> TI32
  | "i64" -> TI64
  | _ -> TUnknown

type t_namespace = {
  language: string;
  name: string;
}

type t_protocol = {
  name: string;
}

type t_field = {
  field_name: string;
  field_type: t_type;
  field_optional: bool;
}

type t_struct = {
  struct_name: string;
  struct_fields: t_field list;
}

type t_decl =  
  | Struct of t_struct

type t_program = {
  namespace: t_namespace;
  protocol: t_protocol;
  decls: t_decl list;
}

(* 
  namespace cpp networking;
  protocol http;   
*)