#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

#define MAX_TERMS 100 // possible maximum terms all over the Polynomials  

struct PolynomialWarehouse {
	Coefficient coef[MAX_TERMS]; 
	Exponent exp[MAX_TERMS]; 
};


typedef struct PolynomialType {
	Exponent degree; // the highest exponent what is not 0  ; if 0 can f(x) = 0

	Coefficient coef[MAX_DEGREE + 1];
	/*
	  idx  0   1    2    3    4    5    6         ...         n-4 n-3 n-2 n-1 n
	  exp  n  n-1  n-2  n-3  n-4  n-5  n-6        ...          4   3   2   1  0

	  ( n is MAX_DEGREE )
	  ( that exp value is zero means not exist )
	
}PolynomialType;
