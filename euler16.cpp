#include <iostream>
#include <gmp.h>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <string>

class Exponentiate
{
public:
	Exponentiate(int b, unsigned int e) : ibase(b), exponent(e) { operation(); };
	~Exponentiate(){}
	void operation();
private:
	int ibase;
	mpz_t base;
	unsigned int exponent;
	int sum=0;
	mpz_t product;
	char* cprod;
};

void Exponentiate::operation()
{
	mpz_init(product);
	mpz_init(base);
	mpz_set_ui(base, ibase);
	mpz_pow_ui(product, base, exponent);
	cprod = mpz_get_str(NULL, 10, product);
	
	for(int i = 0; i< std::strlen(cprod); i++)
	{
		sum += cprod[i]-'0';
	}
	gmp_printf("%Zd ^ %d = %Zd\n", base,exponent, product);
	printf("Sum of digits: %d\n", sum);
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: euler16 base exponent\n";
		return 1;
	}
	Exponentiate e(atoi(argv[1]), atoi(argv[2]));
	
	return 0;
}