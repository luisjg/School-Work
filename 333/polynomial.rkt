;Steve Delgado
;Luis Guzman
;Andrea Rojas
;Project 3

#lang racket


;print the coefficient of a tuple
(define coeff 
  (lambda (t) 
    (cond 
      ((null? t) empty)
      (else
          (car t)))))

;print the exponent of the tuple
(define expon 
  (lambda (t)
    (cond 
      ((null? t) empty)
       (else
            (car(cdr t))))))

;print the tuple formatted with the x^
(define printTerm
  (lambda (t)
    (cond
       ((null? t) empty)
       ;check for power of 0
       ((equal? (expon t) 0)
                (display(coeff t)))
       ;check for power of 1
       ((equal? (expon t) 1)
                (display(coeff t))
                (display "x"))
       ;base case display the x^
       (else
            (display(coeff t))
            (display "x^")
            (display(expon t))))))

;print the polynomial
(define printpoly
  (lambda (p)
    (cond
      ((null? p) empty)
      ;length is 1 only print the last term
      ((=(length p) 1)
       (printTerm (car p))
       (printpoly (cdr p)))
      ;length is greater than 1 print the term and +
      ((>(length p) 1)
       (printTerm (car p))
       (display " + ")
       (printpoly (cdr p)))
      ;base case just print a new line
       (else
        (newline)))))

;evalueates a polynomail when x = v
(define evalpoly
  (lambda (p v)
    "incomplete or missing function" ))

;analyzes the exponent to see if term1 exponent
;is greater than term2 exponent
(define GT
  (lambda (t1 t2)
    (cond
      ((>(expon t1) (expon t2)) (display "True"))
      (else
       (display "False")))))

;analyzes the exponent to see if term1 and term2
;have the same equal exponents
(define EQExp?
  (lambda (t1 t2)
(cond
      ((equal? (expon t1) (expon t2)) (display "True"))
      (else
       (display "False")))))

;return a polynomail equivalent to p
;sorted in decreasing exponent order
(define simplify
  (lambda (p)
    (sort p (lambda (x y) (> (expon x) (expon y))))
    "incomplete or missing function" ))

(define addpoly
  (lambda (p1 p2)
    "incomplete or missing function" ))

(define subtractpoly
  (lambda (p1 p2)
"incomplete or missing function" ))
;multiply a term
(define multiplyterms
  (lambda (t1 t2)
    (map * t1 t2)))

;multiply a polynomial by a constant this doesn't work
(define multiplytermpoly
  (lambda (t p1)
    "incomplete or missing function" ))

(define multiplypoly
  (lambda (p1 p2)
    "incomplete or missing function" ))

(define p1 '((3 2) (8 3) (7 1) (4 0)))
(define p2 '((5 2) (6 4) (-9 3) (4 0)))
(define p3 '((3 2) (-8 1) (5 2) (6 1) (6 2)))
(define p4 '((5 0) (2 3) (-3 1)))
(define p5 '((2 1) ( 1 0)))

(printpoly p3)
(printpoly (simplify p3))
(evalpoly p3 3)
(printpoly (addpoly p1 p2))
(evalpoly (addpoly p1 p2) -2)
(printpoly  (subtractpoly '( ( 3 2) (5 1) (1 0)) '( (6 0) ( 4 1) ( 3 2))))
(define a ( multiplytermpoly '( 3 1) p5))
(evalpoly a 1.5)
(printpoly( multiplypoly p4 p5))
(evalpoly ( multiplypoly p4 p5)  1.25)
(subtractpoly p3 p3)
(printpoly (subtractpoly p3 p3))