(* call by value statically scoped interpreter*)

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
  (*Using and keyword to define two datatypes at the same time*)
  (*Is it should be this? RES_CLOSURE of (string * term) * (string * term) and env = Env of (string -> result)*)
  | RES_CLOSURE of (string*term * env) (* contains a function and an environment*)
  and env = Env of (string -> result);

(*  An environment is a function string -> result.
 *  I've included code for the empty environment
 *  and code that produces the updated environment E[x : t].
 *)

exception UnboundID
(*datatype env = Env of (string -> result)  *)
(*here env is a datatype not function*)
fun emptyenvFun  (x : string) : result = raise UnboundID;
val emptyenv = Env emptyenvFun

(*  update : (string -> result) -> string -> result -> string -> result  *)
fun update (Env e) (x : string) (ty : result) y = if x = y then ty else e y

(* lookup : env -> string -> result*)
fun lookup (Env f) i = f i

(*  update : (string -> result) -> string -> result -> string -> result  *)
fun update (Env e) (x : string) (ty : result) y = if x = y then ty else e y

(*  Here's a partial skeleton of interp_static : (term * env) -> result.
    I've done the first case for you
*) 

(*Here env is a function in interp's parameter*)
fun interp_static (AST_ID i, env)   = lookup env i (* ast id constructor for data type term that represents some variable in lambda calculus, function, application case*)
  | interp_static (AST_NUM n, env)         = RES_NUM n (* data result of number *)
  | interp_static (AST_BOOL b, env)        = RES_BOOL b (* data type result of boolean*)
  | interp_static (AST_FUN (i,e), env)     = RES_CLOSURE(i, e, env) (* constructor for data type term that has string and term, building something of type result, creates enbironment*)
  | interp_static (AST_APP (e1,e2), env)   = let val interp_e1 = interp_static(e1, env) (* data type result AST_APP evaluates first term recursively *)
                                                 val interp_e2 = interp_static(e2, env) (* data type result AST_APP evaluates second term recursively *)
                                          in
    case (interp_e1, interp_e2) of (RES_SUCC, RES_NUM n) => RES_NUM(n+1)(*if case succ applied to number n, return datatype result n+1*)
                                    | (RES_PRED, RES_NUM 0)  => RES_NUM(0)(*if case pred applied to res_num 0, return datatype result 0*)
                                    | (RES_PRED, RES_NUM(n)) => RES_NUM(n-1)(*if case pred applied to number n, return datatype result n-1*)
                                    | (RES_ISZERO, RES_NUM n) => if (n=0) then RES_BOOL(true) else RES_BOOL(false)(*if case iszero checks n, if n is 0, then true else false*)
                                    | (RES_CLOSURE(s, e, env_e1), re) (* res_closure of type (string*term) env *)
                                                           => let val new_static_env = update (env_e1) s re (*new static environment, updated with string s, but what is re?*)
                                                              in
                                                              interp_static(e, Env new_static_env) (*recursive call to interp_static string e, new environment*)
                                                              end
                                    | (_ , _) => RES_ERROR "Error: Can't apply empty functions" (* empty case ?!? how does this not throw a type error*)
     end

  | interp_static (AST_SUCC, env)          = RES_SUCC (* datatype term ast succ, with environment, returns datatype result AST_SUCC *)
  | interp_static (AST_PRED, env)          = RES_PRED (* datatype term ast pred, with environment, returns datatype result AST_PRED *)
  | interp_static (AST_ISZERO, env)        = RES_ISZERO (* datatype term ast iszero, with environment, returns datatype result AST_ISZERO *)
  | interp_static (AST_IF (e1,e2,e3), env) = (* datatype term ast if then else with environment env, *)
    let val v1 = interp_static(e1, env) (* assigns V1 to the recursive call of interp_static(e1,env) with passing env, evaluates e1 in that environment *)
        val v2 = interp_static(e2, env) (* assigns v2 to the recursive call of interp_static(e2,env) with passing env, evaluates e2 in that environement *)
        val v3 = interp_static(e3, env) (* assigns v3 to the recursive call of interp_static(e3,env) with passing env, evaluates e3 in that environement *)
    in
      case v1 of RES_BOOL(true) => v2 (*if v1 is resbool true then evaluates to v2*)
      | RES_BOOL(false) => v3 (*if v1 is resbool false then evaluates to v3*)
      | _ => RES_ERROR "Error: expression result must be boolean" (*if v1 is not a boolean than throws error*)
    end



(*interp(emptyenv, AST_APP (interp(emptyenv, AST_SUCC), AST_NUM(5)))  *)

(* val franklintest1 = interp_lazy(emptyenv, (fn x => x) 42) *)
val franklintest2 = interp_static(AST_NUM(6), emptyenv)
val franklintest3 = interp_static(AST_IF(AST_BOOL(true),AST_NUM(420),AST_NUM(9)), emptyenv)
val franklintest34 = interp_static(AST_IF(AST_BOOL(false),AST_NUM(420),AST_NUM(623)), emptyenv)



val test1 = AST_APP(AST_IF(AST_BOOL(true), AST_SUCC, AST_PRED), AST_NUM(3)); 
val test11 = interp_static(test1, emptyenv)

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

val test33 = interp_static(test3, emptyenv)
      
(*
  If dynamic scope: 1
  If static scope: 0

*)
      
val test4 = AST_APP(AST_FUN("y", AST_NUM(0)), 
      AST_APP(AST_FUN("x", AST_APP(AST_ID("x"), AST_ID("x"))),AST_FUN("x", AST_APP(AST_ID("x"), AST_ID("x")))));

val test44 = interp_static(test4, emptyenv)
      
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

  val test55 = interp_static(test5, emptyenv)    
                
(*
  If static: 42
  If dynamic: 1
*)    


