#include <stdio.h>
#include "Polynomial.h"

int main() {
	
	Polynomial a = MakeZeroPolynomial();
	SingleAddPolynomial(a, 1, 0);
	SingleAddPolynomial(a, 2, 1);

	Polynomial b = MakeZeroPolynomial();
	SingleAddPolynomial(b, 2, 0);
	SingleAddPolynomial(b, 1, 1);

	PrintPolynomial(a);
	PrintPolynomial(b);

	Polynomial c = AddTwoPolynomial(a, b);

	PrintPolynomial(c);

	c = MultiplyTwoPolynomial(a, b);
	ModifyCoefZeroPolynomial(c, 1);
	ModifyCoefZeroPolynomial(c, 2);
	ModifyCoefZeroPolynomial(c, 0);
	ModifyCoefZeroPolynomial(c, 3);
	PrintPolynomial(c);

	RemovePolynomial(a);
	RemovePolynomial(b);
	RemovePolynomial(c);

	return 0;
}