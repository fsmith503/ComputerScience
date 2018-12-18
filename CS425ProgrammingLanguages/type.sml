datatype typ = VAR of string | INT | BOOL | ARROW of typ * typ

(*  Convert a typ to a string, using as few parentheses as possible.  *)

fun typ2str (VAR a)		= "'" ^ a
|   typ2str INT			= "int"
|   typ2str BOOL		= "bool"
|   typ2str (ARROW(t1 as ARROW(_, _), t2)) =	(*  the tricky bit  *)
      "(" ^ typ2str t1 ^ ") -> " ^ typ2str t2
|   typ2str (ARROW(t1, t2))	= typ2str t1 ^ " -> " ^ typ2str t2


(*  An environment is a function string -> typ.
 *  I've included code for the empty environment
 *  and code that produces the updated environment E[x : t].
 *)

exception UnboundID

type env = (string -> typ)

fun emptyenv (x : string) : typ = raise UnboundID

(*  update : env -> string -> typ -> env  *)

fun update E (x : string) (ty : typ) y = if x = y then ty else E y

