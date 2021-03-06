(define (square x)
  (* x x))

(define (abs x)
  (if (> x 0) x (- x)))

(define (average x y)
  (/ (+ x y) 2) )


(define (sqrt x)
(define (improve_guess guess)
  (average guess (/ x guess))
  )
(define (is_good_enough? guess)
  (< (abs (-(square guess) x)) 0.001)
  )
(define (sqrt_iter guess)
        (if (is_good_enough? guess) guess
        (sqrt_iter  (improve_guess guess)) )
        )
    (sqrt_iter 1.0)
)



(define (improve_guess guess x) (average guess (/ x guess))
  )

(define (is_good_enough? guess x )
  (< (abs (-(square guess) x)) 0.001)
  )

(define (sqrt_iter guess x )
        (if (is_good_enough? guess x ) guess
        (sqrt_iter  (improve_guess guess x) x) )
        )

(define (sqrt x)
    (sqrt_iter 1.0 x))





  (/ (+ (/ x (square guess)) (* 2 guess) ) 3)


new one

(define (factoria x)
  (if (> x 1)
    (* x (factoria (- x 1)))
    1)
  )

(define (factoria x)
  (define (fact_iter product counter)
    (if (< counter (+ x 1))
      (fact_iter (* product counter)
                 (+ counter 1))
      product))
  (fact_iter 1 1))


(define (f n)
  (if (< n 3)
    n
    (+ (f (- n 1)) (* 2 (f (- n 2))) (* 3 (f (- n 3))))
    ))

(define (f n)
  (define (f_iter a b c counter result)
    (if (< counter n)
      (f_iter(+ a (* 2 b) (* 3 c)) a b  (+ counter 1) (+ a (* 2 b) (* 3 c)) result)
      result)
    )
  (if (< n 3)
    n
    (f_iter (f 1) (f 2) (f 3) 3 0)))

