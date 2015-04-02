(define (square x)
  (* x x))

(define (abs x)
  (if (> x 0) x (- x)))

(define (improve_guess guess x)
  (/ (+ (/ x (square guess)) (* 2 guess) ) 3)
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
