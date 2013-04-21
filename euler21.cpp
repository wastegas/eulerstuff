#include <iostream>

void propDiv(int &n, int &pdsum)
{
	for(int i = 1; i < n; ++i)
	{
		if( n % i == 0)
		{
			std::cout << i << ' ';	
			pdsum += i;
		}
	}
}


int main()
{
	int pdsum = 0;
	int a = 0;
	int b = 0;
	int sum = 0;
	int s1 = 0;
	int s2 = 0;
	
	for(int i = 2; i < 20; ++i)
	{
		a = i;
		std::cout << a << ' ';
		propDiv(a, s1);
		std::cout << std::endl;
		b = s1;
		std::cout << b << ' ';
		propDiv(b, s2);
		std::cout << std::endl;
		if( a == s2)
		{
			sum += a;
			sum += b;
		}
	}
	std::cout << sum << std::endl;
	return 0;
}
