**ADT Polynomial is** 

object :    
p(x) = a1 * x^e1 + a2 * x^e2 + a3 * x^e3 + ... + an * x^en ;   
a set of ordered pairs of < ei , ai > where ai in Coefficients and ei in Exponents , ei are integers >= 0 

functions :   
poly , poly1 , poly2 in Polynomial , coef in Coefficient , expon in Exponent 

Polynomial MakeZeroPolynomial()   
return new Polynomial , p(x) = 0 

bool IsZeroPolynomial(const Polynomial poly)   
if poly is p(x) = 0 , return true   
else , return false  

Coefficient CoefPolynomial(const Polynomial poly, const Exponent expon)   
return coefficient of the corresponding expon in a poly

Exponent LeadExpPolynomial(const Polynomial poly)   
return largest Exponent in poly 

void SingleAddPolynomial(Polynomial poly, const Coefficient coef, const Exponent expon)   
modify , poly --> poly + coef * x^expon 

void SingleMultiplyPolynomial(Polynomial poly, const Coefficient coef, const Exponent expon)   
modify , poly --> poly * coef * x^expon 

void ModifyCoefZeroPolynomial(Polynomial poly, const Exponent expon)   
modify , coefficient of the corresponding expon is 0 

Polynomial AddTwoPolynomial(const Polynomial poly1, const  Polynomial poly2)   
return Polynomial : poly1 + poly2 

Polynomial MultiplyTwoPolynomial(const Polynomial poly1, const  Polynomial poly2)   
return Polynomial : poly1 * poly2 

void PrintPolynomial(const Polynomial poly)   
print all of the Exponent and Coefficient in poly    
Coefficient * x^Exponent + ... format( to the second decimal point in Coefficient ) 

double ResultPolynomial(const Polynomial poly, const double variable)   
return double value , x = variable in poly
  
void RemovePolynomial(Polynomial poly)   
remove poly and print message 
