#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

void Print(std::vector<int> v)
{
	for (int e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	std::cout << "------------" << std::endl;
}

int main()
{
	std::vector<int> v{ 1,2,3,4,5 };
	v.push_back(6);
	Print(v);

	auto itr = v.begin();
	v.insert(std::next(itr, 2), 3);
	Print(v);

	v.erase(itr + 1);
	Print(v);

	std::qsort(v.data(), v.size(), sizeof(int),
		[](const void* left, const void* right)->int
		{
			int lhs = *static_cast<const int*>(left);
			int rhs = *static_cast<const int*>(right);

			return rhs - lhs;
		}
	);
	Print(v);

	v.clear();
	Print(v);
}