#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

#define MAX_DEGREE 100 // possible maximum exponent of polynomial 

struct PolynomialType {
	Exponent degree; // the highest exponent what is not 0  ; if 0 can f(x) = 0

	Coefficient coef[MAX_DEGREE + 1];
	/*
	  idx  0   1    2    3    4    5    6         ...         n-4 n-3 n-2 n-1 n
	  exp  n  n-1  n-2  n-3  n-4  n-5  n-6        ...          4   3   2   1  0

	  ( n is MAX_DEGREE )
	  ( that exp value is zero means not exist )
	*/
};

// O(1)
Polynomial MakeZeroPolynomial(){
	Polynomial new_poly = calloc(sizeof(*new_poly), 1);
	if (new_poly == NULL) {
		printf("ERROR : MEMORY IS NOT ENOUGH IN <make_Polynomial> FUNCTION \n\n");
		exit(1);
	}
	return new_poly;
}
// O(1)
bool IsZeroPolynomial(const Polynomial poly) {
	if (poly->degree == 0 && poly->coef[MAX_DEGREE] == 0.0)
		return true;
	else
		return false;
}
// O(1)
Coefficient CoefPolynomial(const Polynomial poly, const Exponent expon){

	if (expon < 0) {
		printf("ERROR : EXPONENT INVALID VALUE ( SMALLER THAN 0 ) IN <coef_Polynomial> FUNCTION \n\n");
		exit(1);
	}

	Coefficient result_coef = 0.0; 

	if (MAX_DEGREE >= expon)
		result_coef = poly->coef[MAX_DEGREE - expon];

	return result_coef;
}

// O(1)
Exponent LeadExpPolynomial(const Polynomial poly){
	return poly->degree;
}

// O(1)
void SingleAddPolynomial(Polynomial poly, const Coefficient coef, const Exponent expon) {
	if (expon > MAX_DEGREE) {
		printf("ERROR : EXPONENT IN VALID VALUE ( BIGGER THAN SETTED MAX : %d ) IN <attach_Polynomial> FUNCTION \n\n", MAX_DEGREE);
		exit(1);
	}

	poly->coef[MAX_DEGREE - expon] += coef;

	if (expon > poly->degree)
		poly->degree = expon;

}

// O(N) ; N : degree in poly
void SingleMultiplyPolynomial(Polynomial poly, const Coefficient coef, const Exponent expon) {
	if (expon < 0) {
		printf("ERROR : EXPONENT INVALID VALUE ( SMALLER THAN 0 ) IN <coef_Polynomial> FUNCTION \n\n");
		exit(1);
	}
	if (poly->degree + expon > MAX_DEGREE) {
		printf("ERROR : EXPONENT INVALID VALUE ( BIGGER THAN SETTED MAX : %d ) IN <single_Mult_Polynomial> FUNCTION \n\n", MAX_DEGREE);
		exit(1);
	}

	/* Multiply */
	for (int i = poly->degree; i >= 0; i--) {
		if (poly->coef[MAX_DEGREE - i] != 0.0) {
			poly->coef[MAX_DEGREE - i - expon] = poly->coef[MAX_DEGREE - i] * coef;
			poly->coef[MAX_DEGREE - i] = 0.0;
		}
	}

	/* renew degree (LeadExp)  */
	poly->degree += expon;
}

// O(N) ; N : degree in poly
void ModifyCoefZeroPolynomial(Polynomial poly, const Exponent expon) {
	if (expon > MAX_DEGREE) {
		printf("ERROR : EXPONENT INVALID VALUE ( BIGGER THAN SETTED MAX : %d ) IN <modify_Zero_Polynomial> function> \n\n", MAX_DEGREE);
		exit(1);
	}

	poly->coef[MAX_DEGREE - expon] = 0.0;

	/* renew degree (LeadExp)  */
	if (expon == poly->degree) {
		poly->degree = 0;
		for (int i = expon - 1; i >= 0; i--)
			if (poly->coef[MAX_DEGREE - i] != 0.0) {
				poly->degree = i;
				break; 
			}
	}
}

// O(N) N ; max(degree in poly1 , degree in poly2) 
Polynomial AddTwoPolynomial(const Polynomial poly1, const  Polynomial poly2) {
	Polynomial result_poly = MakeZeroPolynomial();
	Exponent now_exp = 0;

	/* add two poly in result */
	while (now_exp <= poly1->degree || now_exp <= poly2->degree) {
		SingleAddPolynomial(result_poly, poly1->coef[MAX_DEGREE - now_exp] + poly2->coef[MAX_DEGREE - now_exp], now_exp);
		now_exp++;
	}


	/*degree (LeadExp) set in result */
	result_poly->degree = now_exp - 1;

	return result_poly;
}

// O(N*M) ; N : degree in poly1 , M : degree in poly2 
Polynomial MultiplyTwoPolynomial(const Polynomial poly1, const  Polynomial poly2) {
	Polynomial result_poly = MakeZeroPolynomial();

	/* multiply two poly in result */
	for (int i = 0; i <= poly1->degree; i++) {
		if (poly1->coef[MAX_DEGREE - i] != 0) {
			for (int j = 0; j <= poly2->degree; j++) {
				if (poly2->coef[MAX_DEGREE - j] != 0) {
					SingleAddPolynomial(result_poly, poly1->coef[MAX_DEGREE - i] * poly2->coef[MAX_DEGREE - j], i + j);
				}
			}
		}
	}

	/*degree (LeadExp) set in result */
	result_poly->degree = poly1->degree + poly2->degree;

	return result_poly;
}

// O(N) ; N : degree in poly
void PrintPolynomial(const Polynomial poly) {

	/* Lead exp poly print */
	printf("%.2f ", poly->coef[MAX_DEGREE - poly->degree]);
	if (poly->degree != 0) {
		printf(" * x^%d ", poly->degree);
	}

	/* rest poly print */
	for (int i = poly->degree - 1; i >= 0; i--) {
		if (poly->coef[MAX_DEGREE - i] != 0) {
			printf(" + %.2f ", poly->coef[MAX_DEGREE - i]);
			if (i != 0) {
				printf(" * x^%d ", i);
			}
		}
	}

	printf("\n");
}

// O(N) ; N : degree in poly
double ResultPolynomial(const Polynomial poly, const double variable) {
	double resultv = 0.0;
	double mulv = 1.0;

	resultv += poly->coef[MAX_DEGREE];

	for (int i = 1; i <= poly->degree; i++) {
		mulv *= variable;
		if (poly->coef[MAX_DEGREE - i] != 0)
			resultv += (mulv * poly->coef[MAX_DEGREE - i]);
	}

	return resultv;
}

// O(1) 
void RemovePolynomial(Polynomial poly) {
	free(poly);
	printf("REMOVE SUCCESS !!\n");
}