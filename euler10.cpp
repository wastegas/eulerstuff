// Euler 10
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		cout << "Usage: euler10 <some number>" << endl;
		return -1;
	}
	
	long long MAX	= 0;
	long long sum	= 0;
	long long y 	= 0;
	long long j		= 0;
	MAX = atoi(argv[1]);
	
	map<long long, bool> p;
	map<long long, bool>::iterator it;
	
	for(long long i = 2; i <= MAX; i++)
		p.insert(make_pair(i,true));
	
	// Sieve of Eratosthenes
	for(long long i = 2; i <= MAX; i++)
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
	
	for(it=p.begin(); it!=p.end();++it)
	{
		if((*it).second == true)
			sum += (*it).first;
	}
	cout << "Sum of all primes below " << MAX << ": " << sum << endl;	
	return 0;
}
