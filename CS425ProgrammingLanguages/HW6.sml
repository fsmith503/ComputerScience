
datatype typ = VAR of string | INT | BOOL | ARROW of typ * typ

(*1 "2.1i"*)
val int = INT;

(*2 "2.1ii"*)
val num = INT;
val bool = BOOL;
val result = ARROW(num,bool);

(*3 " 2.1iii first solution"*)
val a = VAR("a");
val b = VAR("b")
val first = ARROW(a,b);
val second = ARROW(a,b);
val third = ARROW(first,second);

(*3 "2.1iii second solution"*)
val first = ARROW(VAR("a"),VAR("b"));
val third = ARROW(first,first);

datatype term = AST_ID of string 
| AST_NUM of int
| AST_BOOL of bool
| AST_FUN of (string * typ * term) 
| AST_APP of (term * term) 
| AST_SUCC | AST_PRED | AST_ISZERO
| AST_IF of (term * term * term)


(*2 "2.2i"*)
val five = AST_NUM(5);
val pred = AST_PRED;
val succ = AST_SUCC;
val first = AST_APP(pred,five);
val second = AST_APP(succ,first);

 
 (*2 "2.2ii"*)
 val seven = AST_NUM(7);
 val usebool = AST_BOOL(true);
 val five = AST_NUM(5);
 val resutl = AST_IF(seven,usebool,five);
 
 (*2 "2.2iii"*)
 (* "fn a : int => f a a"*)

 val f = AST_ID("a");
 val a = INT;
 val app = AST_APP(f,f);
 val result = AST_FUN("a",a,app);