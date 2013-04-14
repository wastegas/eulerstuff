#include <iostream>
#include <gmpxx.h>

int main()
{
	mpz_class max;
	mpz_class i;
	mpz_class n;
	mpz_class P;

	max = 600851475143;	
	n = max;
	P = 0;

	for(i = 2; i * i < n;)
	{
		if(n % i == 0)
		{
			n = n / i;
			P = i;
		}
		else
		{
			i++;
		}
	}
	if ( n > P)
		P = n;

	std::cout << P << " is the largets primefactor for " << max << std::endl;
	
	return 0;
}
