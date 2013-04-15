#include <gmpxx.h>
#include <iostream>

int main()
{
	mpz_class sum;
	mpz_class sumsqr;
	mpz_class sqrdiff;

	sum = 0;
	sumsqr = 0;
	sqrdiff = 0;

	for (int i = 1; i <= 100; ++i) {
		sum += i;
		sumsqr += i * i;
	}

	sqrdiff = (sum * sum) - sumsqr;

	std::cout << "The difference between the sum of the\n"
	          << "squares of the first one hundred natural\n"
       	          << "numbers and the square of the sum is " << sqrdiff << std::endl;

	return 0;
}	
