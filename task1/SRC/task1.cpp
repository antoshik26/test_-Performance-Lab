#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char** argv)
{
	int n = 0;
	bool key = false;
	int m = 0;
	std::string s;
	int next = 1;
	std::vector<int> result;
	
	if (argc != 3)
	{
		std::cout << "error: invalid number of arguments" << std::endl;
		return (-1);
	}
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	if (n <= 0 || m <= 0)
	{
		std::cout << "error: invalid arguments" << std::endl;
		return (-1);
	}
	result.push_back(1);
	do
	{
		next += m - 1;
		if (next > n)
		{
			key = false;
			while (key == false)
			{
				next -= n;
				if (next < n)
					key = true;
			}
		}
		result.push_back(next);
	}
	while (result[0] != next);
	for (size_t i = 0; i < result.size() - 1; i++)
	{
		std::cout << result[i];
	}
	return (0);
}
