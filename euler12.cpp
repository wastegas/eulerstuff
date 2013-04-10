#include <iostream>
#include <stdio.h>
#include <cmath>

class TriangleNo
{
public:
	TriangleNo() {getTerm();};
	void getTerm();
	void TriangleTerm();
private:
	long long Tn;
	long long n;
	int count;
};

void TriangleNo::getTerm()
{
	Tn=1;
	n=1;
	TriangleTerm();
	std::cout << "Tn " << Tn << " has " << count << " divisors"<< std::endl;
}

void TriangleNo::TriangleTerm()
{
	int p;
	count = 0;
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

int main()
{
	TriangleNo T;
	return 0;
}
