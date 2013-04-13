#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <gmp.h>

using namespace std;

class euler13
{
public:
	euler13()
	{
		sumDigits();
	}

private:
void sumDigits()
{
	mpz_init(sum);
	mpz_init(dline);
	mpz_set_ui(sum,0);
	mpz_set_ui(dline,0);
	ifstream iStream("digits");
	string line;
	
	if(iStream.is_open())
	{
		while(getline(iStream,line))
		{
			mpz_set_str(dline, line.c_str(), 10);
			mpz_add(sum,sum, dline);
		}
		iStream.close();
		gmp_printf("%Zd", sum);
		mpz_clear(dline);
		mpz_clear(sum);
	}
	else
	{
		std::cout << "unable to open file" << std::endl;
	}
}
	
	mpz_t sum;
	mpz_t dline;
};


int main()
{
	euler13 D;
	cout << endl;

	return 0;
}
