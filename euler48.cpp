#include <iostream>
#include <gmp.h>
#include <string>
#include <cstring>

class euler48
{
public:
	euler48(){
		sumSeries();
	}
private:
	void sumSeries()
	{
		mpz_init(sum);
		mpz_set_ui(sum,0);
		mpz_init(prod);
		mpz_set_ui(prod,0);
		mpz_init(base);
	
		for(unsigned long int power = 1; power<=1000; power++)
		{
			mpz_set_ui(base,power);
			mpz_pow_ui(prod,base,power);
			mpz_add(sum, sum, prod);
		}
	
		chrsum = mpz_get_str(NULL, 10, sum);
		strsum = chrsum;
		//gmp_printf("%Zd\n", sum);
		std::cout << "The last 10 digits are " << strsum.substr(std::strlen(chrsum)-10);
		std::cout << std::endl;
	}
	mpz_t sum;
	mpz_t prod;
	mpz_t base;
	char* chrsum;
	std::string strsum;
};


int main()
{
	euler48 p;
	return 0;
}
