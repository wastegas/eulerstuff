#include <iostream>

void propDiv(int &n, int &pdsum)
{
	for(int i = 1; i < n; ++i)
	{
		if( n % i == 0)
		{
			pdsum += i;
		}
	}
}


int main()
{
	int a = 0;
	int b = 0;
	int sum = 0;
	int s1 = 0;
	int s2 = 0;
	
	for(int i = 2; i < 10000; ++i)
	{
		a = i;
		propDiv(a, s1);
		b = s1;
		propDiv(b, s2);
		if( a == s2 && b == s1 && a != b)
		{
			sum += a;
		}
		s1 = 0;
		s2 = 0;
	}
	std::cout << "sum of amicable numbers under 10000 is " <<  sum << std::endl;
	return 0;
}
