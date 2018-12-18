(* Skeleton file for Assignment 6, Problem 4 *)
(* Derived from code by Chris Stone *)

exception Unimplemented

(* An implementation of environments *)
type 'a env = string -> 'a option
val empty = fn _ => NONE
fun lookup (f, x) = f x
fun extend (f, k : string, x) = 
      fn k' => if (k=k') then SOME x else f k'

datatype prop =
    Var of string
  | Or  of prop * prop
  | And of prop * prop
  | If  of prop * prop
  | Not of prop

type assignment = bool env

(* satisfy: prop * assignment * (assignment -> bool) -> bool 

    "satisfy(p, asn, k)" checks whether there is an assignment
    of booleans to variables that: 
      (a) makes proposition p true
      (b) agrees with the given assignment asn 
          (i.e., doesn't change any values already appearing in asn) 
      (c) makes the continuation k return true.
      
    Note that in this version, we are just checking whether
    an assignment exists or not.  (If you're bored, you might
    consider how you'd rewrite the code so that you could
    get out the satisfying assignment.)
*)
 
fun satisfy (Var v, asn, k) =
     (case lookup (asn, v) of
        NONE       => 
        let
          val env1 = extend(asn, v, true)
          val env2 = extend(asn, v, false)
        in
          case k(env1) of
            true => true
            | false => (case k(env2) of
              true => true
              | false => false)
        end
      | SOME true  => true
      | SOME false => false)

  | satisfy (And(p1,p2), asn, k) = 
      (case (satisfy(p1, asn, k), satisfy(p2, asn, k)) of
        (true, true) => true
        | (_, _) => false)


  | satisfy (Or(p1, p2), asn, k) = 
      (case (satisfy(p1, asn, k), satisfy(p2, asn, k)) of
        (false, false) => false
        | (_, _) => true)
        
  | satisfy (Not p, asn, k) =
      falsify(p, asn, k)

  | satisfy (If(p1, p2), asn, k) =
      satisfy(Or(Not p1, p2), asn, k)

(* falsify: prop * assignment * (assignment -> bool) -> bool 
    Just like satisfy except we are looking for an assignment
    that makes the given proposition *false*.
 *)

and falsify (Var v, asn, k) =
     (case lookup (asn, v) of
        NONE       => 
        let
          val env1 = extend(asn, v, false)
          val env2 = extend(asn, v, true)
        in
          case k(env1) of
            true => true
            | false => (case k(env2) of
              true => true
              | false => false)
        end
      | SOME true  => false  
      | SOME false => true)

  | falsify (And(p1,p2), asn, k) = 
      (case (falsify(p1, asn, k), falsify(p2, asn, k)) of
        (true, true) => false
        | (_, _) => true)
        

  | falsify (Or(p1, p2), asn, k) = 
      (case (falsify(p1, asn, k), falsify(p2, asn, k)) of
        (false, false) => true
        | (_, _) => false)
        

  | falsify (Not p, asn, k) =  
      satisfy(p, asn, k)

  | falsify (If(p1, p2), asn, k) =
      falsify(Or(Not p1, p2), asn, k)


(* satisfiable: prop -> bool
   falsifiable: prop -> bool
   valid: prop -> bool.

   Determine whether the given proposition is satisfiable,
   falsifiable, or valid.  Valid is easy, since validity
   means cannot-be-falsified.
 *)
fun satisfiable p = satisfy(p, empty, fn _ => true)
fun falsifiable p = falsify(p, empty, fn _ => true)
fun valid(p) = not (falsifiable p)

(* Two test inputs.  You should definitely come
   up with your own tests as well.
 *)

val P = Var "p"
val Q = Var "q"
val R = Var "r"


val test11 = And(Or(P,Q), Not(P)) 
val test12 = If(And(And(Or(P,Q), If(P,R)), If(Q,R)), R)
val test13 = Not(And(Or(P,Q), Not(P)));
val test14 = And(Not(P),P);

val test1 = And(Or(P,Q), Not(P)) 
val test2 = If(And(And(Or(P,Q), If(P,R)), If(Q,R)), R)
val test3 = Not(And(Or(P,Q), Not(P)))
