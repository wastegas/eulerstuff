#include <iostream>
#include <stdio.h>
#include <cmath>

class TriangleNo
{
public:
	TriangleNo()
	       : Tn(1), n(1), count(0)	
	{
		TriangleTerm();
		std::cout << "Tn " << Tn << " has " << count << " divisors"<< std::endl;
	}

			
private:
	void TriangleTerm()
	{
		for(;;)
		{
			Tn=(n*(n+1))/2;
			n++;
			for(long long d=1; d<=sqrt(Tn); d++)
			{	
				if(Tn % d == 0)
				{
					count++;
				}
			}
			count *= 2;
			if(count > 500)
				break;
			count = 0;
		}	
	
	}

	long long Tn;
	long long n;
	int count;
};


int main()
{
	TriangleNo T;
	return 0;
}
