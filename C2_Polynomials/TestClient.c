#include <stdio.h>
#include "Polynomial.h"

int main() {
	
	Polynomial a = MakeZeroPolynomial();
	AttachPolynomial(a, 1, 0);
	AttachPolynomial(a, 2, 1);

	Polynomial b = MakeZeroPolynomial();
	AttachPolynomial(b, 2, 0);
	AttachPolynomial(b, 1, 1);

	PrintPolynomial(a);
	PrintPolynomial(b);

	Polynomial c = AddTwoPolynomial(a, b);

	PrintPolynomial(c);

	c = MultiplyTwoPolynomial(a, b);

	PrintPolynomial(c);

	RemovePolynomial(a);
	RemovePolynomial(b);
	RemovePolynomial(c);

	return 0;
}