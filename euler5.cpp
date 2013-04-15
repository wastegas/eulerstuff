#include <boost/math/common_factor.hpp>		// :P
#include <numeric>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> l;
	for(int i = 1; i <= 20; ++i)
		l.push_back(i);

	int sum = 0;
	sum = std::accumulate(l.begin(), l.end(), 1, boost::math::lcm_evaluator<int>());
	std::cout << sum << std::endl;

	return 0;
}
