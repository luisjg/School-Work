#lang racket
;----------------
;Project 4
;Steve Delgado
;Luis Guzman
;Andrea Rojas
;----------------
(define nextchar '())
(define pos 0)
(define tokenList '())

(define syntaxError
   (lambda ()
     (newline)
      (raise-user-error 
            "Syntax error at token position: "     (-    pos    1) 
             "with next character: "     nextchar )))

(define removeSpaces
  (lambda (lst)
    (cond 
      ((null? lst) '())
      ((eqv? (car lst) #\space) (removeSpaces(cdr lst)))
      (else
       (cons (car lst) (removeSpaces (cdr lst)))))))

(define getChar
  (lambda (lst)
    (newline)
    (cond
      ((< pos (length lst)) (set! nextchar (list-ref lst pos)) (display "getChar: ")(display pos)(display " ")(display nextchar)(set! pos (+ pos 1)))
      (else 
       (syntaxError)
      ))))

(define match
  (lambda (char)
   (cond
     ((eqv? nextchar char)
      (cond 
        ((not(eqv? char #\$)) (getChar tokenList))))
      (else
       syntaxError))))

(define S
  (lambda ()
    (E)
    (match #\$)))

(define E
  (lambda ()
    (T)
    (cond
      ((eqv? nextchar #\+) (match #\+)(E))
      ((eqv? nextchar #\-) (match #\-)(E))
      )))

(define T
  (lambda ()
    (F)
    (cond
      ((eqv? nextchar #\*) (match #\*)(T))
      ((eqv? nextchar #\/) (match #\/)(T)))))

(define F
  (lambda ()
    (cond
      ((or (char-alphabetic? nextchar) (char-numeric? nextchar)) (match nextchar))
      ((eqv? nextchar #\() (match #\()(E) (match #\)))
      (else
       (syntaxError)))))

(define end
  (lambda ()
    (set! tokenList '())
    (set! pos 0)
    (set! nextchar '())
    ))

(define start
  (lambda ()
    (newline)
    (getChar tokenList)
    (S)
    (cond 
      ((eq? pos (length tokenList)) (newline) (display "Succesful parse")(end))
     (else
      (end)
      (newline)
      (display "Unsuccessful Parse")
      (syntaxError)))))

(define parse 
  (lambda  (inputstring)
     (set! tokenList (removeSpaces (string->list inputstring)))
;display the tokenlist
      (display "tokenList: ")(display tokenList)
      (start)))

;-------------------------------------------------------------------
;output
;
;> (parse " 3   + 4  9 * 8   $")
;tokenList: (3 + 4 9 * 8 $)
;
;getChar: 0 3
;getChar: 1 +
;getChar: 2 4
;getChar: 3 9
;Unsuccessful Parse
;Syntax error at token position:  -1 "with next character: " ()
;> (parse  "5  *   (  z  + y ) -  8 $")
;tokenList: (5 * ( z + y ) - 8 $)
;
;getChar: 0 5
;getChar: 1 *
;getChar: 2 (
;getChar: 3 z
;getChar: 4 +
;getChar: 5 y
;getChar: 6 )
;getChar: 7 -
;getChar: 8 8
;getChar: 9 $
;Succesful parse
;> (parse  " x + y - 5$"  )
;tokenList: (x + y - 5 $)
;
;getChar: 0 x
;getChar: 1 +
;getChar: 2 y
;getChar: 3 -
;getChar: 4 5
;getChar: 5 $
;Succesful parse
;> (parse  " 3 * ( q + w  /   5)    $")
;tokenList: (3 * ( q + w / 5 ) $)
;
;getChar: 0 3
;getChar: 1 *
;getChar: 2 (
;getChar: 3 q
;getChar: 4 +
;getChar: 5 w
;getChar: 6 /
;getChar: 7 5
;getChar: 8 )
;getChar: 9 $
;Succesful parse
;> (parse " ( a * ( b + c/ ( 3 * d)   )  )" )
;tokenList: (( a * ( b + c / ( 3 * d ) ) ))
;
;getChar: 0 (
;getChar: 1 a
;getChar: 2 *
;getChar: 3 (
;getChar: 4 b
;getChar: 5 +
;getChar: 6 c
;getChar: 7 /
;getChar: 8 (
;getChar: 9 3
;getChar: 10 *
;getChar: 11 d
;getChar: 12 )
;getChar: 13 )
;getChar: 14 )
;
;Syntax error at token position:  14 "with next character: " #\)
;> (parse   "5 + 6 * 8) $" ) 
;tokenList: (5 + 6 * 8 ) $)
;
;
;Syntax error at token position:  14 "with next character: " #\)
;> (parse "  1 * 2 )  -  3 + z $"  )
;tokenList: (1 * 2 ) - 3 + z $)
;
;
;Syntax error at token position:  14 "with next character: " #\)
;---------------------------------------------------------------------


