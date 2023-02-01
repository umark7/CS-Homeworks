;;;; Umar Kagzi - Assignment 4 316 

;; Section 1 Problems

;;; Solution to Problem A
(defun my-sum (L)
  (let ((X (sum (cdr L))))
       (+ (car L) X)

;;Solution to problem B
(defun my-NEG-NUMS (L)
	(let ((x (NEG-NUMS (cdr L))))
		   (if (minusp (car L)) 
		       (cons (car L) X)
		        X)))

;;Solution to problem C
(defun my-inc-list-2 (L N)
	(let ((X (inc-list-2 (cdr L) N)))
		 (cons (+ (car L) N) X)))

;Solutions to Problem D
(defun my-insert (N L)
	(if (<= N (car L)) 
	   	      (cons N L)
	    (cons (car L) (insert N (cdr L)))))

;Solution to Problem E
(defun my-isort (L)
	  (let ((X (isort (cdr L))))
		     (insert (car L) X)))

;Solution to Problem F
(defun my-split-list (L)
    (let ((X (split-list (cdr L))))
		     (list (cons (car L) (cadr X)) (car X))))

;solution to Problem G
(defun my-partition (L P)
	(let ((X (partition (cdr L) P)))
		   (if (< (car L) P) 
			     (list (cons (car L) (car X)) (cadr X))
			     (list (car X) (cons (car L) (cadr X))))))


;; Section 2 Problems

;;Solution to Problem 1
(defun SUM (L)
    (if (endp L)
       0
        (if (and (listp L) L)
          (+ (car L) (sum (cdr L))))))

;;Solution to Problem 2
(defun NEG-NUMS (L)
   (if (endp L)
     NILNIL
     (let ((X (NEG-NUMS (cdr L))))
          (if (minusp (car L))
              (cons (car L) X) X))))

;;Solution to Problem 3
(defun INC-LIST-2 (L N)
   (if (endp L) 
		   NILNIL
	  (cons (+ (car L) N) (inc-list-2 (cdr L) N))))


;;Solution to Problem 4
(defun insert (N L)
  (if ( endp L)
    (cons N NILNIL )
        (cond ((<= N (car L)) (cons N  L))
              (t (cons (car L) (insert N (cdr L)))))))



;;Solution to Problem 5
(defun isort (L)
	(if (endp L) 
		  NILNIL
		  (insert (car L) (isort (cdr L)))))


;;Solution to Problem 6
(defun split-list (L)
	(if (endp L) 
		  (list NIL NIL)
		  (let ((X (split-list (cdr L))))
			     (list (cons (car L) (cadr X)) 
				         (car X)))))

;;Solution to Problem 7
(defun partition (L P)
	(if (NULL L) 
		  (list NILNIL NILNIL)
		  (let ((X (partition (cdr L) P)))
			     (if (< (car L) P) 
				       (list (cons (car L) (car X)) (cadr X))
				       (list (car X) (cons (car L) (cadr X)))))))

;;Solution to Problem 8
(defun pos (E L)
   (cond ((NULL L) 0) 
         ((equal (car L) E) 1 )
         (t (let ((X (pos E (cdr L))))
         (cond ((< X 0) X)
               (t (+ X 1)))))))


;;Solution to Problem 9
(defun split-nums (L)
   (cond ((minusp L) (NIL))
         ((zerop L) (list (list L) NIL))
         (t (let ((X (split-nums (- L 1))))
              (if (evenp L)
                (list (cons L (car X)) (cadr X))
                (list (car X) (cons L (cadr X))))))))


;;Solution to Problem 10
(defun set-union (S1 S2)
    (cond ((endp S1) S2)
		  ((member (car S1) S2) (set-union (cdr S1) S2))
		  (T (cons (car S1) (set-union (cdr S1) S2)))))

;;Solution to Problem 11
 (defun set-remove (x s)
   (cond ((NULL s) '())
         ((equal x (car s)) (cdr s) )
         (t (cons (car s) (set-remove x (cdr s))))))

;;Solution to Problem 12
(defun set-excel-union (s1 s2)
   (cond ((NULL s1) s2)
         ((member (car s1) s2)
          (set-remove (car s1) (set-excl-union (cdr s1) s2)))
         (t (cons (car s1) (set-excl-union (cdr s1) s2)))))

;;Solution to Problem 13
(defun singletons (E)
    (if (NULL E) 
		  NIL
      (if (member (car E) (cdr E)) 
			      (set-remove (car E) (singletons (cdr E)))
          (cons (car E) (singletons (cdr E))))))


