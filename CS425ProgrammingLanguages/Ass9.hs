{- Problem 1.a -}
ones :: [Int]
ones = 1 : ones

{- Problem 1.b -}
intList :: Int -> [Int]
intList n = n : intList (n+1)

{- Problem 1.c -}
takeN :: Int -> [a] -> [a]
takeN 0 xs = []
takeN n (x:xs) = x : takeN (n-1) xs

{- Problem 2.a -}
countBy2 :: Int -> [Int]
countBy2 n = n : countBy2 (n+2)

evens :: [Int]
evens = countBy2 0

odds :: [Int]
odds = countBy2 1

{- Problem 2.b -}
merge :: [Int] -> [Int] -> [Int]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) = x : y : merge xs ys

-- Both `merge evens odds` and `length (merge evens odds)` do not terminate
-- because they both try to evaluate the whole structure which is infinite. On
-- the other hand, `takeN 5 (merge evens odds)` terminates because it only looks
-- at a part of the infinite structure.

{- Problem 2.c -}
i,ii,iii,iv :: [Int]
i   = map (\x -> x ^ 3) (intList 0)
ii  = map (3^) (intList 0)
iii = merge (intList 0) (map (^2) (intList 0))
iv  = map (0-) (intList 1)


{- Problem 3.a -}
data Error a = Ret a | Err String deriving Show

instance Functor Error
instance Applicative Error

instance Monad Error where
  return x = Ret x
  (Ret a) >>= f = f a
  (Err s) >>= f = Err s

{- Problem 3.b -}
err :: String -> Error a
err = Err

{- Problem 3.c -}
data Exp = Times Exp Exp
         | Div   Exp Exp
         | Const Int
         deriving Show

eval :: Exp -> Error Int
eval (Times e1 e2) =
   case eval e1 of
      Ret v1 ->
        case eval e2 of
          Ret v2 -> Ret (v1 * v2)
          Err s -> Err s
      Err s -> Err s
eval (Div   e1 e2) =
   case eval e1 of
      Ret v1 ->
        case eval e2 of
          Ret v2 -> if v2 == 0 then Err "divby0"
                   else Ret (v1 `div` v2)
          Err s -> Err s
      Err s -> Err s
eval (Const i)     = Ret i

{- Problem 3.d -}
eval2 :: Exp -> Error Int
eval2 (Times e1 e2) =
  eval2 e1 >>= \e1' ->
  eval2 e2 >>= \e2' ->
  return (e1' * e2')
eval2 (Div   e1 e2) =
  eval2 e1 >>= \e1' ->
  eval2 e2 >>= \e2' ->
    case e2' of
      0 -> err "divby0"
      _ -> return (e1' `div` e2')
eval2 (Const i) = return i
