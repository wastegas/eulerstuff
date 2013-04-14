#include <gmp.h>
#include <gmpxx.h>
#include <iostream>

static mpz_class F;
static mpz_class p1;
static mpz_class p2;
static mpz_class sum;


void Fib()
{
	if(F < 4000000)
	{
		F = p1 + p2;
		p2 = p1;
		p1 = F;
		
		if (F % 2  == 0)
		{
			sum += F;
		}

		
		Fib();
	}
}

int main()
{
	F = 0;
	p1 = 0;
	p2 = 1;
	sum = 0;

	Fib();
	
	std::cout << "Sum of even Fibonacci terms below 4,000,000 = " <<  sum << std::endl;
	return 0;
}
