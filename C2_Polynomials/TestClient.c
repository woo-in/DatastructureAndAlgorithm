#include <stdio.h>
#include "Polynomial.h"

int main() {
	polynomial a1 = make_Zero_Polynomial();
	attach_Polynomial(a1, 2, 2);
	print_All_Polynomial(a1);

	return 0;
}