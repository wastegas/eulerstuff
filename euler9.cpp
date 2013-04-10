#include <iostream>

class Triplet
{
public:
	Triplet()
		: a(0), b(0), c(0)
	{
		calcABC();
	}
private:
	void calcABC()
	{
		for( a = 1; a < 1000; a++ )
		{
			for( b = a + 1; b < 1000; b++)
			{
				c = 1000 - a - b;
				if(a * a + b * b == c * c)
				{
					result();
					break;
				}
			
			}	
		}	
	}

	void result()
	{
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "a+b+c=" << a + b + c << std::endl;
		std::cout << "a.b.c=" << a*b*c << std::endl;
	}

	int a;
	int b;
	int c;
};


int main(void)
{
	Triplet triplet;
	
	return 0;
}
