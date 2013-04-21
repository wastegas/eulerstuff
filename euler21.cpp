#include <iostream>

void propDiv(int &n, int &pdsum)
{
	for(int i = 1; i < n; ++i)
	{
		if( n % i == 0)
			pdsum += i;
	}
}


int main()
{
	int pdsum = 0;
	int a = 0;
	int b = b;
	int sum = 0;


	for(int i = 2; i < 10000; ++i)
	{
		a = i;
		propDiv(i, a);
		propDiv(a, b);
		if( a != b )

	}

	return 0;
}
