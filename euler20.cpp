#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <gmp.h>
#include <cstring>

class factorial
{
public:
	factorial(unsigned int ii) 
		: i(ii) 
	{
		factsum();
	}

private:
	void factsum()
	{	
	
		mpz_init(f);
		mpz_set_ui(f,1);
	
		for (unsigned int n = i ; n!=0; n--)
		{
			mpz_mul_ui(f, f, n);
		}
		strf = mpz_get_str(NULL,10,f);
		for(int i = 0; i< std::strlen(strf); i++)
		{
			fsum += strf[i]-'0';
		}
	
		gmp_printf("%d! %Zd\n",i,f);
		printf("Sum of digits: %d\n", fsum);
	}

	unsigned int i;
	mpz_t f;
	int fsum=0;
	char* strf;
};

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Usage: euler20 <some number>" << std::endl;
		return -1;
	}

	factorial F(atoi(argv[1]));
	
	return 0;
}
