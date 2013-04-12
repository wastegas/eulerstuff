#include <iostream>
#include <gmp.h>
#include <cstring>
#include <stdio.h>

class Fibonacci
{
	unsigned long n;
	mpz_t F;
	char* strF;
public:
	Fibonacci() {getTermK();};

private:
void getTermK()
{
	mpz_init(F);
	mpz_set_ui(F,0);
	n = 1;
	nthTerm();

	printf("Term %ld had 1000 digits\n",n);
	gmp_printf("And here's the digits!\n%Zd\n", F);
	
	
}

void nthTerm()
{
	for(;;)
	{
		mpz_fib_ui(F,n);
		strF = mpz_get_str(NULL,10,F);
		if(std::strlen(strF)==1000)
			break;
		n++;
	}
}


};

int main()
{
	Fibonacci f;
	return 0;
}
