#include <iostream>
#include <vector>

class euler14
{
public:
	euler14()
		: n_(1), term_(0), count_(0)
	{
		collatz();
	}

private:
	struct Holder_ {
		int n;
		int chains;
	};
	
	void collatz()
	{
	   for(n_ = 1; n_ <= 1000000 ;++n_)
	   {
		term_ = n_;
		++count_; 
		while(term_ !=1)
		{
			++count_;
			if(term_ % 2 == 0){
				term_ = term_ / 2;
			}
			else{
				term_ = 3 * term_ +1;
			}
		} 
		record_ = {n_, count_};
		holder_.push_back(record_);
		term_ = 0;
		count_ = 0;
	  }
	  print();
	}

	void print()
	{
		sort(holder_.begin(), holder_.end(), [] (const Holder_& a, const Holder_& b) -> bool 
		{
			return a.chains > b.chains;
		});

		auto it = holder_.begin();
		
		std::cout << it->n << " " << it->chains << std::endl;
		
	}


	int n_;
	long long term_;
	int count_;
	std::vector<Holder_>holder_;
	Holder_ record_;
};

int main()
{
	euler14 c;
	return 0;
}
