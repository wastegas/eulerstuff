#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl;
using std::vector; using std::string;
using std::to_string;

bool palindrome(const std::string& s)
{
	string r(s);
	reverse(r.begin(), r.end());
	return r == s;
}

int main()
{
	string s;
	int n = 0;
	vector<int> p;
	for(int i = 100; i <= 999; ++i){
		for (int y = 100; y <= 999; ++y){
			n = i * y;
			if(palindrome(to_string(n)))
				p.push_back(n);
		}
	}

	sort( p.rbegin(), p.rend());

	auto it=p.begin();
	cout << *(it) << endl;

	return 0;
}
