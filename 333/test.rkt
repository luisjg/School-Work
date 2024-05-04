#lang racket
(define fact
(lambda (n)
  (if (= n 0) 1
      (* n (fact (- n 1))))))
(display "Git out")
(define coeff 
  (lambda (lst t) 
    (cond 
      ((null? lst)
       "not here"
       )
      ((equal? t (car (car lst)))
       (car (car lst))
       )
      (else (coeff (cdr lst) t)))))
(define expon 
  (lambda (lst t)
    (cond 
      ((null? lst) "none of it"
                   )
      ((equal? t (car (car lst)))
       (car(cdr(car lst)))
       )
      (else (expon (cdr lst) t)))))
(define printTerm
  (lambda (lst)
    (cond
      ((equal? 0 (car (car lst)))
       (car (cdar list))
       )
      (else (printTerm (cdr lst)))
      )))