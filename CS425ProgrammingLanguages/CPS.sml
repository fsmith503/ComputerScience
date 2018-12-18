
(* pow1 is a simple recursive definition of a power function *)
fun pow1 n 0 = 1
	| pow1 n m = n * (pow1 n (m-1))

val test = pow1 5 2


fun return n = n;

(* pow is the definition of a power fucntion that uses continuation passing style with the type
powk : int -> int -> (int -> a) -> *)
fun pow n 0 k = k 1
	| pow n m k = (pow n ( m - 1 )) (fn v => k ( n * v ));

val test1 = pow 6 2 return 

(* prod1 is a simple recursive definition that computes the product of a list *)
fun prod1 [] = 1
	| prod1 (x::xs) = x * (prod1 xs)

val test2 = prod1([1,2,3,4])

(* prod is the definition that computes the product of a list using continuation passing style with the type
prodk : int list -> (int -> a) -> a *)
fun prod [] k = k 1 
	| prod (x::xs) k = (prod xs) (fn v => k ( x * v ));

val test3 = prod([1,2,3]) return