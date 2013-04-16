#include <iostream>
#include <fstream>

int main()
{
	std::string line;
	std::string dstr;
	std::ifstream in("digits");
	
	if(!in.is_open())
		return -1;

	while(std::getline(in, line,'\n')){
		for(auto it=line.begin(); it != line.end(); ++it)
			dstr += (*it);
	}
	in.close();
	
	int prod = 0;
	int tmp = 1;
	for (unsigned int i = 0; i < dstr.size(); ++i){
		for(unsigned int j = i; j < i+5; ++j) {
			tmp *= dstr[j] - '0';
		}
		if (tmp > prod)
			prod = tmp;
		tmp = 1;
	}
	std::cout << prod << std::endl;

	return 0;
}
