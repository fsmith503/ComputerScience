(* call by name dynamically scoped interpreter*)


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
  

(*  An environment is a function string -> result.
 *  I've included code for the empty environment
 *  and code that produces the updated environment E[x : t].
 *)

exception UnboundID
datatype env = Env of (string -> term) (* env of string to erm *)   (* changed environment from string->result to string->term *)
fun emptyenvFun  (x : string) : term = raise UnboundID;
val emptyenv = Env emptyenvFun

(*  update : (string -> result) -> string -> result -> string -> result  *)
fun update (Env e) (x : string) (ty : term) y = if x = y then ty else e y

(* lookup : env -> string -> result*)
fun lookup (Env f) i = f i

(*  Here's a partial skeleton of interp : (env * term) -> result.
    I've done the first case for you
*)
fun interp_lazy (env, AST_ID i)          = interp_lazy(env, lookup env i)  (*lookup up i in that environment which returns a result, then calls interp_lazy  *)
  | interp_lazy (env, AST_NUM n)         = RES_NUM(n) (* datatype result of number n*)
  | interp_lazy (env, AST_BOOL b)        = RES_BOOL(b) (* datatype bool of bool b*)
  | interp_lazy (env, AST_FUN (i,e))     = RES_FUN(i,e) (* datatype result of (string * term) *)
  | interp_lazy (env, AST_APP (e1,e2))   = (case interp_lazy(env, e1) of (* case matching e1 to different e2 cases*)
  	                               RES_PRED => (case interp_lazy(env, e2) of (* case matching if e1 is res_pred then recursively evaluate e2 in the environment and perform arithmetic*)
                                                    RES_NUM(0) => RES_NUM(0) (* if its res_num(0) then return res_num(0)*)
                                                  | RES_NUM(n) => RES_NUM(n-1) (*if its res_num(n) then return res_num(n-1)*)
                                                  | _ => RES_ERROR "Cannot increment non integer" ) (* if its anything else wildcard then error then raise error message*)
  	                               | RES_SUCC => (case interp_lazy(env, e2) of (* case matching if e1 is res_succ then recursively evaluate e2 in the environment and perform arithmetic*)
                                                   RES_NUM(0) => RES_NUM(0) (* if its res_num(0) then return res_num(0)*)
                                                  | RES_NUM(n) => RES_NUM(n+1) (* if its res_num(n) then return res_num(n+1)*)
  	                                              | _ => RES_ERROR "Cannot decrement non integer" ) (* if its anything else wildcard then throws an error*)
                                   | RES_ISZERO => (case interp_lazy(env, e2) of (* if e1 in app is res_iszero, then apply to e2 *)
                                                   RES_NUM(0) => RES_BOOL(true) (* case if e2 is res_num(0) then return res_bool(true) *)
                                                  | RES_NUM(n) => RES_BOOL(false)(* case if e2 is res_num(n) then return res_bool(false) *)
                                                  | _ => RES_ERROR "Cannot compare non integer" ) (* if its anything else wildcard then throws an error*)
                                   (*| RES_FUN (i, e) => interp( Env (update env i (interp (env, e2))), e) *)
                                     | RES_FUN (i, e) => interp_lazy(Env(update env i e2), e) (* since call by name, just put e2, do not evaluate, example is the infinite loop examples with (lambax.42) omega, you just put it there, you dont evaluate*)
                                     )                                                          
  | interp_lazy (env, AST_SUCC)          = RES_SUCC (*case interp AST_SUCC, returns result RES_SUCC*)
  | interp_lazy (env, AST_PRED)          = RES_PRED (*case interp AST_PRED, returns result RES_PRED*)
  | interp_lazy (env, AST_ISZERO)        = RES_ISZERO (*case interp AST_ISZERO, returns result RES_ISZERO*)
  | interp_lazy (env, AST_IF (e1,e2,e3)) = (case interp_lazy(env, e1) of RES_BOOL(false) => interp_lazy(env, e3) (*case interp ast_if e1,e2,e3, if e1 is false, then evaluate to e3*)
                                    | RES_BOOL(true) => interp_lazy(env, e2) (* case matching if e1 is true, then evaluate to e2*)
                                    | _ => RES_ERROR "Error: e1 is not a boolean" ) (*case e1 is something else, raise error e1 is not a boolean*)
 
(*interp(emptyenv, AST_APP (interp(emptyenv, AST_SUCC), AST_NUM(5)))  *)

(*
val first = AST_FUN(AST_ID("x"),AST_NUM(42));
val second = AST_FUN(AST_ID("x"),AST_APP(AST_ID("x"),AST_ID("x")));
val third = interp(AST_APP(first,second));
*)

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

