#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdbool.h>
typedef struct polynomial_Type* Polynomial;
typedef double Coefficient;
typedef int Exponent;

Polynomial MakeZeroPolynomial();
bool IsZeroPolynomial(const Polynomial poly);
Coefficient CoefPolynomial(const Polynomial poly, const Exponent expon);
Exponent LeadExpPolynomial(const Polynomial poly);
void AttachPolynomial(Polynomial poly, const Coefficient coef, const Exponent expon);
void ModifyCoefZeroPolynomial(Polynomial poly, const Exponent expon);
void SingleMultiplyPolynomial(Polynomial poly, const Coefficient coef, const Exponent expon);
Polynomial AddTwoPolynomial(const Polynomial poly1, const  Polynomial poly2);
Polynomial MultiplyTwoPolynomial(const Polynomial poly1, const  Polynomial poly2);
void PrintPolynomial(const Polynomial poly);
double ResultPolynomial(const Polynomial poly, const double variable);
void RemovePolynomial(Polynomial poly);

#endif 


