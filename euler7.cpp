#include <iostream>
#include <map>
#include <algorithm>
#include <gmpxx.h>

using namespace std;

int main()
{
	mpz_class MAX;
	mpz_class sum;
	mpz_class y;
	mpz_class j;

	MAX = 500000;
	sum = 0;
	y = 0;
	j = 0;
	
	map<mpz_class, bool> p;
	map<mpz_class, bool>::iterator it;
	
	for(mpz_class i = 2; i <= MAX; i++)
		p.insert(make_pair(i,true));
	
	// Sieve of Eratosthenes
	for(mpz_class i = 2; i <= MAX; i++)
	{
		if(p[i]==true)
		{
			for(j = i*i; j <= MAX;j = i*i+i*y)
			{
				p[j] = false;
				y++;
			}
			j = 0;
			y = 0;
		}
	}
	
	int count = 0;
	for(it=p.begin(); it!=p.end();++it)
	{
		if((*it).second == true)
			++count;
		if(count == 10001){
			std::cout << "The 10001st prime is "
			       	<< (*it).first << std::endl;
		break;
		}
	}
	return 0;
}
