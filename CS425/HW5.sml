fun sum_list (xs : int list) =
  if null xs
  then 0
  else hd xs + sum_list(tl xs);
  
sum_list([1,2,3,4]);

datatype E = NUM of int | PLUS of E*E | TIMES of E*E;
fun interp(NUM x) = x 
| interp(PLUS(x,y)) = (interp x) + (interp y) 
| interp(TIMES(x,y)) = (interp x) * (interp y);

interp (NUM 1);
interp (PLUS (NUM 1, NUM 2));
interp (PLUS (PLUS (NUM 1, NUM 2), NUM 3));
interp (PLUS (PLUS (NUM 1, NUM 2), (TIMES (NUM 3, NUM 4))));

datatype tree = NIL | CONS of (tree * tree) | LEAF of int;
fun treemap(f, NIL) = NIL
|treemap(f,CONS(x,y)) = CONS(treemap(f,x), treemap(f,y)) 
|treemap(f, LEAF x) = LEAF(f(x));

fun square x = x * x;

Control.Print.printDepth := 100; 
val L = CONS (CONS (LEAF 1, LEAF 2), CONS (CONS (LEAF 3, LEAF 4), LEAF 5));
treemap(square, L);




