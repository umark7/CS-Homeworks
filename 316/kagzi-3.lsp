;;;; Umar Kagzi - Assignment 3 316

;;; Solution to Problem 1

(defun MIN-2 (A B) 
    (cond ((not (numberp A)) 'error)
          ((not (numberp B)) 'error)
          ((> A B) B)
          ((<= A B) A)))

;;; Solution to Problem 2

(defun SAFE-AVG (x y) 
    (cond ((numberp x)
          (numberp y)
          (/(+ x y) 2))))

;;; Solution to Problem 3

(defun ODD-GT-MILLION (x)
    (and (and (and (integerp x) (numberp x)) (oddp x))
    (> x 1000000)))

;;; Solution to Problem 4 - Had difficulty answering
;; Used cdr, returns NIL otherwise

(defun MULTIPLE-MEMBER (x y)
    (member x (cdr (member x y))))

;;; Solution to Problem 5 - Had difficulty answering
;; Otherwise used in branching for case

(defun MONTH->INTEGER (month)
    (case month
        (JANUARY 1)
        (FEBRUARY 2)
        (MARCH 3)
        (APRIL 4)
        (MAY 5)
        (JUNE 6)
        (JULY 7)
        (AUGUST 8)
        (SEPTEMBER 9)
        (OCTOBER 10)
        (NOVEMBER 11)
        (DECEMBER 12)
        (otherwise 'ERROR)))

;;; Solution to Problem 6

(defun SCORE->GRADE (s)
    (when (numberp s)
        (cond ((>= s 90) 'A)
              ((>= s 87) 'A-)
              ((>= s 83) 'B+) 
              ((>= s 80) 'B)
              ((>= s 77) 'B-)
              ((>= s 73) 'C+)
              ((>= s 70) 'C)
              ((>= s 60) 'D)
              (t 'F))))


;;; Solution to Problem 7

(defun GT (x y)
	(and (and (numberp x) (numberp y))
	(> x y)))

;;; Solution to Problem 8

(defun SAME-PARITY (x y)
	(or (and (and (integerp x) (integerp y))
    (and (evenp x) (evenp y))
    (and (numberp x) (numberp y)))
    (and (and (integerp x) (integerp y))
    (and (oddp x) (oddp y))
    (and (numberp x) (numberp y)))))

;;; Solution to Problem 9

(defun SAFE-DIV (x y)
	(and (and (and (numberp x) (numberp y))
	(not (zerop y)))
	(/ x y)))