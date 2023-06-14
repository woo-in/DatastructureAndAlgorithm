#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

#define MAX_DEGREE 1002 // (possible maximum exponent of polynomial) 

struct polynomial_Type {
	exponent degree; // the highest exponent what is not 0  ; if 0 can f(x) = 0 

	coefficient coef[MAX_DEGREE + 1];
	/*
	  idx  0   1    2    3    4    5    6         ...         n-4 n-3 n-2 n-1 n
	  exp  n  n-1  n-2  n-3  n-4  n-5  n-6        ...          4   3   2   1  0

	  ( n is MAX_DEGREE )
	  ( that exp value is zero means not exist )

	  typeInfo
	  degree : int
	  exponent : int
	  coefficient : double

	*/
};



polynomial make_Zero_Polynomial() {
	polynomial new_Poly = calloc(sizeof(*new_Poly), 1);
	if (new_Poly == NULL) {
		printf("ERROR : MEMORY IS NOT ENOUGH IN <make_Polynomial> function \n\n");
		exit(1);
	}
	return new_Poly;
}

bool is_Zero_Polynomial(const polynomial poly) {
	if (poly->degree == 0 && poly->coef[MAX_DEGREE] == 0.0)
		return true;
	else
		return false;
}

coefficient return_Coef_Polynomial(const polynomial poly, const exponent expon) {
	if (expon < 0) {
		printf("ERROR : EXPONENT INVALID VALUE ( SMALLER THAN 0 ) IN <coef_Polynomial> function \n\n");
		exit(1);
	}

	coefficient return_Coef = 0.0; // for return 
	if (MAX_DEGREE >= expon)
		return_Coef = poly->coef[MAX_DEGREE - expon];

	return return_Coef;
}

exponent return_Lead_Polynomial(const polynomial poly) {
	return poly->degree;
}

void attach_Polynomial(polynomial poly, const coefficient coef, const exponent expon) {
	if (expon > MAX_DEGREE) {
		printf("ERROR : EXPONENT IN VALID VALUE ( BIGGER THAN SETTED MAX : %d ) IN <attach_Polynomial> function \n\n", MAX_DEGREE);
		exit(1);
	}

	poly->coef[MAX_DEGREE - expon] += coef;

	if (expon > poly->degree)
		poly->degree = expon;

}

void modify_Zero_Polynomial(polynomial poly, const exponent expon) {
	if (expon > MAX_DEGREE) {
		printf("ERROR : EXPONENT INVALID VALUE ( BIGGER THAN SETTED MAX : %d ) IN <modify_Zero_Polynomial> function> \n\n", MAX_DEGREE);
		exit(1);
	}

	poly->coef[MAX_DEGREE - expon] = 0.0;

	if (expon == poly->degree) {
		poly->degree = 0;
		for (int i = 0; i < expon; i++)
			if (poly->coef[MAX_DEGREE - i] != 0.0) {
				poly->degree = i;
			}
	}
}
// input expon > 0 
void single_Mult_Polynomial(polynomial poly, const coefficient coef, const exponent expon) {
	if (expon < 0) {
		printf("ERROR : EXPONENT INVALID VALUE ( SMALLER THAN 0 ) IN <coef_Polynomial> function \n\n");
		exit(1);
	}
	if (poly->degree + expon > MAX_DEGREE) {
		printf("ERROR : EXPONENT INVALID VALUE ( BIGGER THAN SETTED MAX : %d ) IN <single_Mult_Polynomial> function> \n\n", MAX_DEGREE);
		exit(1);
	}

	for (int i = poly->degree; i >= 0; i--) {
		if (poly->coef[MAX_DEGREE - i] != 0.0) {
			poly->coef[MAX_DEGREE - i - expon] = poly->coef[MAX_DEGREE - i] * coef;
			poly->coef[MAX_DEGREE - i] = 0.0;
		}
	}

	poly->degree += expon;
}

polynomial add_Polynomial(const polynomial poly1, const  polynomial poly2) {
	polynomial return_Poly = make_Zero_Polynomial();
	exponent now_Exp = 0;

	while (now_Exp <= poly1->degree || now_Exp <= poly2->degree) {
		attach_Polynomial(return_Poly, poly1->coef[MAX_DEGREE - now_Exp] + poly2->coef[MAX_DEGREE - now_Exp], now_Exp);
		now_Exp++;
	}

	return_Poly->degree = now_Exp - 1;

	return return_Poly;
}
polynomial mult_Polynomial(const polynomial poly1, const  polynomial poly2) {
	polynomial return_Poly = make_Zero_Polynomial();
	for (int i = 0; i <= poly1->degree; i++) {
		if (poly1->coef[MAX_DEGREE - i] != 0) {
			for (int j = 0; j <= poly2->degree; j++) {
				if (poly2->coef[MAX_DEGREE - j] != 0) {
					attach_Polynomial(return_Poly, poly1->coef[MAX_DEGREE - i] * poly2->coef[MAX_DEGREE - j], i + j);
				}
			}
		}
	}
	return_Poly->degree = poly1->degree + poly2->degree;

	return return_Poly;
}




/*
polynomial return_Poly = make_Zero_Polynomial();
int i;

for (i = 0; i <= poly1->degree; i++)
	if (poly1->coef[MAX_DEGREE - i] != 0.0)
		return_Poly->coef[MAX_DEGREE - i] = poly1->coef[MAX_DEGREE - i];

return_Poly->degree = poly1->degree;

for (i = 0; i <= poly2->degree; i++)
	if (poly2->coef[MAX_DEGREE - i] != 0.0)
		single_Mult_Polynomial(return_Poly, poly2->coef[MAX_DEGREE - i], i);

return return_Poly;
*/



void print_All_Polynomial(const polynomial poly) {
	printf("%.2f ", poly->coef[MAX_DEGREE - poly->degree]);
	if (poly->degree != 0) {
		printf(" * x^%d ", poly->degree);
	}

	for (int i = poly->degree - 1; i >= 0; i--) {
		if (poly->coef[MAX_DEGREE - i] != 0) {
			printf(" + %.2f ", poly->coef[MAX_DEGREE - i]);
			if (i != 0) {
				printf(" * x^%d ", i);
			}
		}
	}

	printf("\n");
	return;
}

double result_Polynomial(const polynomial poly, const double inpt) {
	double result_V = 0.0;
	double mul_V = 1.0;

	result_V += poly->coef[MAX_DEGREE];

	for (int i = 1; i <= poly->degree; i++) {
		mul_V *= inpt;
		if (poly->coef[MAX_DEGREE - i] != 0)
			result_V += (mul_V * poly->coef[MAX_DEGREE - i]);
	}

	return result_V;
}

void remove_Polynomial(polynomial poly) {
	free(poly);
	printf("REMOVE SUCCESS !!\n");
}