#include <iostream>
#include <map>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

int main()
{
	std::map <char, int> alpha;
	char a = 'A';
	for(int i=1; i <= 26; i++)
	{
		alpha.insert(std::make_pair<char&, int&>(a, i));
		a++;
	}

	std::ifstream fs("names.txt");
	std::string line;

	const std::string delims("\",");
	std::vector<std::string> nameslist;
	if(fs.is_open())
	{
		while(getline(fs, line))
		{
			std::string::size_type begIdx, endIdx;
			std::string name;	
			begIdx = line.find_first_not_of(delims);
			while(begIdx != std::string::npos)
			{
				endIdx = line.find_first_of(delims, begIdx);
				if(endIdx == std::string::npos)
				{       	
					endIdx = line.length();
				}
				for (int i = begIdx; i <= endIdx-1; ++i)
				{
					name += line[i];
				}
				nameslist.push_back(name);
				name.clear();
				begIdx = line.find_first_not_of(delims, endIdx);
			}
		}
	
	}	
	fs.close();

	sort(nameslist.begin(), nameslist.end());
	int sumword = 0;
	long sum = 0;
	for(auto it = nameslist.begin(); it != nameslist.end(); ++it)
	{
		auto pos = it - nameslist.begin() + 1;
		for(auto &c : (*it)){
			sumword += alpha.find(c)->second;
		}
		sumword *= pos;
		sum += sumword;
		sumword = 0;
	}
	std::cout << "The sum of all names x it's position is " << sum << std::endl;
	return 0;


}
