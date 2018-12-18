(* call by name statically-scoped interpreter*)


(*  Here's a skeleton file to help you get started on Interpreter 1.
 * Original version by Geoffrey Smith - http://users.cs.fiu.edu/~smithg/
 *)

datatype term
  = AST_ID of string
  | AST_NUM of int
  | AST_BOOL of bool
  | AST_FUN of (string * term)
  | AST_APP of (term * term)
  | AST_SUCC
  | AST_PRED
  | AST_ISZERO
  | AST_IF of (term * term * term)

datatype result
  = RES_ERROR of string
  | RES_NUM   of int
  | RES_BOOL  of bool
  | RES_SUCC
  | RES_PRED
  | RES_ISZERO
  | RES_FUN   of (string * term)
  

 | RES_CLOSURE of (string*term * env) (* contains a function and an environment*)
  and env = Env of (string -> (env * term));  

(*  An environment is a function string -> result.
 *  I've included code for the empty environment
 *  and code that produces the updated environment E[x : t].
 *)

exception UnboundID
(*datatype env = Env of (string -> (env * term)) (* changed environment from string->result to string->term *) *)
fun emptyenvFun  (x : string) : (env * term) = raise UnboundID;
val emptyenv = Env emptyenvFun

(*  update : (string -> result) -> string -> result -> string -> result  *)
fun update (Env e) (x : string) (ty : (env * term)) y = if x = y then ty else e y

(* lookup : env -> string -> (env * term) *)
fun lookup (Env f) i = f i

(*  Here's a partial skeleton of interp : (env * term) -> result.
    I've done the first case for you
*)
fun interp_lazy (env, AST_ID i)          = interp_lazy(lookup env i) (*lookup i in the environment, then recursive call to interp_lazy*)
  | interp_lazy (env, AST_NUM n)         = RES_NUM(n) (* returns result res num n*)
  | interp_lazy (env, AST_BOOL b)        = RES_BOOL(b) (* returns result res bool b*)
  | interp_lazy (env, AST_FUN (i,e))     = RES_FUN(i,e) (* datatype result of (string*term)*)
  | interp_lazy (env, AST_APP (e1,e2))   = (case interp_lazy(env, e1) of  (* case matching e1 to different e2 cases *)
                                   RES_PRED => (case interp_lazy(env, e2) of (* if e1 is res_pred, then recursively evaulate e2 in environment*)
                                                    RES_NUM(0) => RES_NUM(0) (* if its res_num(0) then return res_num(0)*)
                                                  | RES_NUM(n) => RES_NUM(n-1) (* if its res_num(n) then return res_num(n-1) *)
                                                  | _ => RES_ERROR "Cannot increment non integer" ) (* if its wildcard its something else so raises error*)
                                   | RES_SUCC => (case interp_lazy(env, e2) of (* if e1 is res_succ, then recursively evaluate e2 in the environment *)
                                                   RES_NUM(0) => RES_NUM(0) (* if e2 is res_num(0) then return res_num(0)*)
                                                  | RES_NUM(n) => RES_NUM(n+1) (* if e2 is res_num(n) then return res_num(n+1) *)
                                                  | _ => RES_ERROR "Cannot decrement non integer" ) (* if its wildcard anything else so raises error *)
                                   | RES_ISZERO => (case interp_lazy(env, e2) of (* if e1 is res_iszero, then recursively evaluates e2 in environment*)
                                                   RES_NUM(0) => RES_BOOL(true) (* if its res_num(0) then returns res_bool(true) *)
                                                  | RES_NUM(n) => RES_BOOL(false) (* if its res_num(n) then returns res_bool(false) *)
                                                  | _ => RES_ERROR "Cannot compare non integer" ) (* if its wildcard so anything else, so raises error*)
                                   (*| RES_FUN (i, e) => interp( Env (update env i (interp (env, e2))), e) *)
                                    | RES_CLOSURE(s, e, env_e1) (* res_closure of type (string*term) env *)
                                                           => let val new_static_env = update env_e1 s (env , e2) (* updates environment string s then pair (env, e2) e2 is a terms  *)
                                                              in
                                                              interp_lazy(Env new_static_env, e) (*recursive call to interp_lazy in new environment and term e*)
                                                              end
                                    | _ => RES_ERROR "Error: Can't apply empty functions" (* empty case ?!? how does this not throw a type error*)   
                                     )                                                          
  | interp_lazy (env, AST_SUCC)          = RES_SUCC (*case interp AST_SUCC, returns result RES_SUCC*)
  | interp_lazy (env, AST_PRED)          = RES_PRED (*case interp AST_PRED, returns result RES_PRED*)
  | interp_lazy (env, AST_ISZERO)        = RES_ISZERO (* case interp AST_ISZERO, returns result RES_ISZERO *)
  | interp_lazy (env, AST_IF (e1,e2,e3)) = (case interp_lazy(env, e1) of RES_BOOL(false) => interp_lazy(env, e3) (*case interp ast_if e1,e2,e3, if e1 is false, then evaluate to e3*)
                                    | RES_BOOL(true) => interp_lazy(env, e2) (* case matching if e1 is true, then evaluate to e2*)
                                    | _ => RES_ERROR "Error: e1 is not a boolean" ) (*case e1 is something else, raise error e1 is not a boolean*)
 
(*interp(emptyenv, AST_APP (interp(emptyenv, AST_SUCC), AST_NUM(5)))  *)

(* val franklintest1 = interp_lazy(emptyenv, (fn x => x) 42) *)
val franklintest2 = interp_lazy(emptyenv, AST_NUM(6))
val franklintest3 = interp_lazy(emptyenv ,AST_IF(AST_BOOL(true),AST_NUM(420),AST_NUM(9)))
val franklintest34 = interp_lazy(emptyenv ,AST_IF(AST_BOOL(false),AST_NUM(420),AST_NUM(623)))



val test1 = AST_APP(AST_IF(AST_BOOL(true), AST_SUCC, AST_PRED), AST_NUM(3)); 
val test11 = interp_lazy(emptyenv, test1)

(*
Always 3
*)

(*

val test2 = AST_APP(AST_FUN("f", AST_APP(AST_FUN("x", AST_APP(AST_ID("f"), AST_ID("x"))), AST_NUM(5))), AST_FUN("z", AST_ID("x")));
val = test22 interp_lazy(emptyenv, test2)

*)

 (*
 If dynamic scope: 5
 If static scope: Error
 *)

val test3 = AST_APP(
        AST_FUN("x", 
          AST_APP(
            AST_FUN("f", 
              AST_APP(
                AST_FUN("x", 
                  AST_APP(AST_ID("f"), AST_NUM(3))
                )
              , AST_NUM(1)
              )
            )
          ,AST_FUN("y", AST_ID("x"))
          )
        ), 
      AST_NUM(0));

val test33 = interp_lazy(emptyenv, test3)
      
(*
  If dynamic scope: 1
  If static scope: 0

*)
      
val test4 = AST_APP(AST_FUN("y", AST_NUM(0)), 
      AST_APP(AST_FUN("x", AST_APP(AST_ID("x"), AST_ID("x"))),AST_FUN("x", AST_APP(AST_ID("x"), AST_ID("x")))));

val test44 = interp_lazy(emptyenv, test4)
      
(*
  If lazy: Returns 0
  If eager: Loops to infinity
*)
      
val test5 = AST_APP(AST_FUN("z", 
        AST_APP(AST_FUN("x",
            AST_APP(AST_FUN("f",
              AST_APP(AST_FUN("x",
                AST_APP(AST_FUN("z",
                  AST_APP(AST_ID("f"), AST_NUM(3))
                ), AST_NUM(0))
              ),AST_NUM(1))
            ),AST_FUN("y", AST_ID("x")))),
          AST_APP(AST_SUCC, AST_ID("z"))
        )),AST_NUM(41));  

  val test55 = interp_lazy(emptyenv, test5)    
                
(*
  If static: 42
  If dynamic: 1
*)    






