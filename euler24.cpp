#include <iostream>
#include <vector>
#include <algorithm>

class euler24
{
public:
	euler24(int _n, int _i) : n(_n), numPerm(_i) {nthPermutation();}

private:
	void nthPermutation()
	{
		std::vector<int> perm(n);
		int count = 1;
		
		for(int p=0;p<n; p++)
			perm[p]=p;
	
		while(count < numPerm)
		{
			int N = n;
			int i = N-1;
		
			while(perm[i -1] >=perm[i])
				i = i - 1;
		
			int j = N;
			
			while(perm[j - 1] <= perm[i - 1])
				j = j - 1;
		
			swap(i - 1, j - 1, perm);
		
			i++;
			j=N;
			
			while(i < j)
			{
				swap(i - 1, j - 1, perm);
				i++;
				j--;
			}
			count++;
		}
	
		std::cout << "The millionth lexographic permutation is: ";
		
		for_each(perm.begin(), perm.end(), [] (int p) {
			std::cout << p;
		});
	}

	void swap(int i, int j, std::vector<int>& perm)
	{
		int k = perm[i];
		perm[i] = perm[j];
		perm[j] = k;
	}

	int n;
	int numPerm;
};

int main()
{
	euler24 lex(10, 1000000);
	std::cout << std::endl;
	return 0;
}
