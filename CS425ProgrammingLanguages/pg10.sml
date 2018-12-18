exception Eval of int;

fun program(n) = if n < 1 then raise Eval(n) else program(n-1)
(1 + program(n)) handle Eval => y = y + 1

val temp = program(0);
