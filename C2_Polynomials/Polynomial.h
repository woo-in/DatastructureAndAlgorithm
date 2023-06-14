#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/*  header about polynomial */
/*  2023.06.09 made by woo_in  */

#include <stdbool.h>
typedef struct polynomial_Type* polynomial;
typedef double coefficient;
typedef int exponent;


polynomial make_Zero_Polynomial();
bool is_Zero_Polynomial(const polynomial poly);
coefficient return_Coef_Polynomial(const polynomial poly, const exponent expon);
exponent return_Lead_Polynomial(const polynomial poly);
void attach_Polynomial(polynomial poly, const coefficient coef, const exponent expon);
void modify_Zero_Polynomial(polynomial poly, const exponent expon);
void single_Mult_Polynomial(polynomial poly, const coefficient coef, const exponent expon);
polynomial add_Polynomial(const polynomial poly1, const  polynomial poly2);
polynomial mult_Polynomial(const polynomial poly1, const  polynomial poly2);
void print_All_Polynomial(const polynomial poly);
double result_Polynomial(const polynomial poly, const double inpt);
void remove_Polynomial(polynomial poly);

#endif 


