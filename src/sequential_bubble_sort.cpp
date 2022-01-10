
#include <vector>
#include <list>
#include <sstream>
#include "utils/random_factory.h"
#include "utils/time_profiler.h"

void sequentialBubbleSort(std::vector<int> &arr)
{
	bool sorted = true;
	const int q = arr.size() - 1;
	for(int k = 1; k <= q; ++k)
	{
		for(int j = 0; j <= q - k; ++j)
		{
			if(arr.at(j) > arr.at(j + 1))
			{
				std::swap(arr[j], arr[j + 1]);
				sorted = false;
			}
		}
		if(sorted){ return; }
	}
}

void print(std::vector<int> &arr)
{
	for (auto i : arr) { std::cout << i << " "; }
	std::cout << std::endl << std::endl;
}

int main()
{
	RandomFactory rf;
	auto gen = rf.create_mersenne_int_engine(0, 999);

	std::ostringstream ss;

	for(int i = 2; i < 20000; i+=500)
	{
		ss.str("");
		ss.clear();

		std::vector<int> arr(i);
		std::generate(std::begin(arr), std::end(arr), gen);

		{
			ss << "n=" << i;
	    	TimeProfiler tp(ss.str().c_str());

			//std::cout << "before sorting:" << std::endl;print(arr);
			sequentialBubbleSort(arr);
			//std::cout << "after sorting:" << std::endl;print(arr);
		}
	}

	return 0;
}

