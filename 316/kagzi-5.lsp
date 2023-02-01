;;;; Umar Kagzi - Assignment 5 316 
;; Partner - Hassan Amjad (316 - 8 PM class)

;; Section 1 Solutions (Nonrecursive Preliminary Problems)

;;Solution to Problem  A
(defun my-index (N L)
	(let ((x (index (- N 1) (cdr L)))

;;Solution to B
(defun my-min-first (L)
	(let ((X (min-first (cdr L))))
		 (if (> (car L) (car X)) 
			 (cons (car X) (cons (car L) (cdr X)))
		 L)))	

;;Problem C Solution 
(defun my-ssort (L)
	(let* ((L1 (MIN-FIRST l))
		   (x  (SSORT (cdr L1))))
		   (cons (car L1) x)))


;; Section 2 Solutions (Main Problems)

;;Solution to problem 1
(defun INDEX (N L)
      (if (endp L)
          'error
          (if (equal N 1)
              (car L)
              (let ((X (INDEX (- N 1)(cdr L))))
                X))))

;;Solution to problem 2
(defun min-first (L)
	(if (endp L) 
		NIL
		(if (= 1 (length L)) 
			L
			(let ((X (min-first (cdr L))))
			(if (> (car L) (car X)) 
				(cons (car X)(cons (car L) (cdr X)))
				L)))))			

;;Solution to problem3
(defun SSORT (L)
	(if (endp L) 
		NIL
		(let((L1 (min-first L)))
			 (cons (car L1) (SSORT (cdr L1))))))

;;Solution to problem 4
(defun QSORT (L)
   (cond ((null L) NIL)
         (t (let ((P1 (partition L (car L))))
                 (cond ((endp (first P1)) (cons (first L)(QSORT (rest L))))
                        (t (let ((x (QSORT (first P1)))
                                 (y (QSORT (second P1))))
                            (append x y))))))))

;;Solution to problem 5
(defun MERGE-LISTS (L1 L2)
	(if (endp L1) 
		L2
		(if (null L2)
			L1
			(if (< (car L1) (car L2)) 
				(cons (car L1) (MERGE-LISTS (cdr L1) L2))
				(cons (car L2) (MERGE-LISTS L1 (cdr L2)))))))

;;Solution to problem 6
(defun MSORT (L)
	(if (endp L)
		NIL
		(if (= (length L) 1);((null? (cdr l)) l)
			L
			(let ((X (split-list L)))
				  (merge-lists (msort (car X)) (msort (cadr X)))))))	

;;Solution to problem 7
(defun REMOVE-ADJ-DUPL (L)
   (if (endp L)
        NIL
	(let ((x (REMOVE-ADJ-DUPL (cdr L))))
	      (if (equalp (car L) (car x))
	           x
		  (cons (car L) x)))))

;;Solution to problem 8
(defun UNREPEATED-ELTS (L)
	(cond ((endp L) NIL)
		  ((or (endp (cdr L)) (not (equal (car L)(cadr L)))) (cons (car L)(UNREPEATED-ELTS(cdr L))))
		  ((or (endp (cddr L)) (not (equal (car L)(caddr L)))) (UNREPEATED-ELTS(cddr L)))
		  (T  (UNREPEATED-ELTS (cdr L)))))

;;Solution to problem 9
(defun REPEATED-ELTS (L)
   (cond ((endp L) NIL)
         ((or (endp (cdr L)) (not (equal (car L) (cadr L)))) (REPEATED-ELTS (cdr L)))
	 ((or (endp (cddr L)) (not (equal (car L) (caddr L)))) (cons (car L) (REPEATED-ELTS (cddr L))))
	 (t (REPEATED-ELTS (cdr L)))))

;;Solution to problem 10
(defun COUNT-REPETITIONS (L)
   (if (endp L)
	NIL
	(let ((x (COUNT-REPETITIONS (cdr L))))
	   (if (equal (car L) (cadr L))
	       (append (list (list (+ 1 (caar x)) (cadar x))) (cdr x))
	       (append (list (list 1 (car L))) x)))))

;;Solution to problem 11
(defun SUBSET (f L)
   (if (endp L)
	NIL
	(let ((x (SUBSET f (cdr L))))
	   	 (if (funcall f (car L))
	       	 (cons (car L) x)
		 x))))

;;Solution to problem 12

(defun OUR-SOME (f L)
   (if (endp L)
	nIL
	(let ((x (OUR-SOME f (cdr L))))
	   (if (funcall f (car L))
			L
		x))))

(defun OUR-EVERY (f L)
	(if (endp L)
		T
	(and (funcall f (car L)) (OUR-EVERY f (cdr L)))))		


;;Solution to problem 13 (includes PARTITION1 and QSORT1)
(defun PARTITION1 (f L P)
	(if (endp L) 
		(list NIL NIL)
		(let ((X (PARTITION1 f (cdr L) P)))
			(if (funcall f (car L) P) 
				(list (cons (car L) (car X)) (cadr X))
				(list (car X) (cons (car L) (cadr X)))))))
				
(defun QSORT1 (f L)
   (cond ((endp L) nIL)
	 (t (let ((Z (PARTITION1 f L (car L))))  
	          (cond ((endp (car Z)) (cons (car L) (QSORT1 f (cdr L))))
		        	 (t (let ((x (QSORT1 f (car Z)))
		                (y (QSORT1 f (cadr Z)))) 
			    		(append  x  y))))))))

;;Solution to problem 14
(defun FOO (f L)
   (if (endp L) 
       () 
       (let* ((x (FOO f (cdr L))) (ls (cdr L))
	     	 (Z (list (cons (funcall f (car L)) ls)))
	     	 (Y (mapcar (lambda (a) (cons (car L) a)) x)))
	     	 (append Z Y))))


;;Solution to problem 15
;; 15 has A and B

;; Solution 15A
(defun TR-ADD (L acc)
   (if (endp L)
	acc
	(TR-ADD (cdr L) (+ (car L) acc))))

(defun TR-MUL (L acc)
   (if (endp L)
	acc
	(TR-MUL (cdr L) (* (car L) acc))))

(defun TR-FAC (X Y)
	(if (= X Y)
		Y
		(TR-FAC (- X 1) (* X Y))))

;;Solution 15 B

(defun SLOW-PRIMEP (N)
	(if (not (integerp N)) 
		NIL
		(if (< N 1)
			NIL
		(=(- N 1) (mod (TR-FAC(- N 1) 1) N)))))

;;Solution to problem 16
;; 16 has A, B, C

;; 16A Solution
(defun TRANSPOSE1 (M)
	(if (endp M)
		NIL
		(if (endp (cdr M))
			(mapcar #'list (car M))
		(mapcar #'cons (car M) (TRANSPOSE1 (cdr M))))))

;;16B Solution
(defun TRANSPOSE2 (m)
   (cond ((endp (cdar m)) (list (mapcar #'car m)))
	 (t (cons (mapcar #'car m) (TRANSPOSE2 (mapcar #'rest m))))))

;;16C SOlution
(defun TRANSPOSE3 (m)
   (apply #'mapcar #'list m))


;;Umar Kagzi 316 Assignment 5