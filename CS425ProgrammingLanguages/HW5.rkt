#lang racket

;1 homework number 1
(define interp (lambda (E)
                (match E
                  (`(+   ,A ,B)(+ (interp A)(interp B)))
                  (`(*   ,A ,B)(* (interp A)(interp B)))
                  ;(`,A  A))))
                  ;(`,A (if (integer? A) then ((A)) else (error "Error: Not a valid E term"))))))
                  (`,A (if (integer? A) A (error "Error: Not a valid E term" ))))))


(interp '(+ 1 2))
(interp '(+ (+ 1 2) (* 3 4)))
(interp 1)
(interp '(+ 1 2))
(interp '(+ (+ 1 2) 3))
(interp '(+ (+ 1 2) (* 3 4)))
;(interp '(cons 1 2))


; homework number 2
(define TR (lambda (E)
             (match E
               (`(+  ,A ,B) `(* ,(TR A),(TR B)))
               (`(*  ,A ,B) `(+ ,(TR A),(TR B)))
               (`,A (if (integer? A) A (error "Error: Not a valid E term" )))
               )))

(TR '(+ 1 2))
(TR '(+ (* 2 3) (* (+ 1 2) (* 8 8))))
(interp (TR '(+ (* 2 3) (* (+ 1 2) (* 8 8)))))
;(eval (TR '(+ (* 2 3) (* (+ 1 2) (* 8 8)))))


;homework number 3
;(car (cons 1 2))
;(cons '('A (cons( 'B 'C)))  '(cons ('B 'C)))
;(cons '('A ( cons( 'B 'C))) '(cdr ('A (cons ('B 'C)))))
;(car (cons 'A 'B))
;3A
(cons(cons 'A (cons 'B 'C)) ( cons 'B 'C))
;3B
(let([x ( cons 'B 'C)]) (cons ( cons 'A x) x))

