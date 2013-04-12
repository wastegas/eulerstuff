#include <iostream>
#include <vector>
#include <algorithm>

class euler24
{
public:
	euler24(int _n, int _i) : n(_n), numPerm(_i) {nthPermutation();}
	void nthPermutation();
	void swap(int, int, std::vector<int>&);
private:
	int n;
	int numPerm;
};

void euler24::nthPermutation()
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
	std::cout << std::endl;
}

void euler24::swap(int i, int j, std::vector<int>& perm)
{
	int k = perm[i];
	perm[i] = perm[j];
	perm[j] = k;
}

int main()
{
	euler24 lex(10, 1000000);
	return 0;
}
