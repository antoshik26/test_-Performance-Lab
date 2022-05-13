#include <iostream>
#include <vector>
#include <fstream>

int main(int argc, char** argv)
{
	std::vector<int> array_vec;
	std::vector<int> count;
	size_t a = 0;
	size_t b = 0;
	int z = 0;
	int min = 0;

	if (argc != 2)
	{
		std::cout << "error: invalid number of arguments" << std::endl;
		return (-1);
	}
	std::ifstream file_1 (argv[1]);
	if (!file_1)
	{
		std::cout << "error: invalid arguments" << std::endl;
		return (-1);
	}
	for (std::string line; std::getline(file_1, line);)
	{
		a = atoi(line.c_str());
		array_vec.push_back(a);
	}
	a = 0;
	while(a < array_vec.size())
	{
		z = array_vec[a];
		b = 0;
		min = 0;
		while (b < array_vec.size())
		{
			min += abs(array_vec[b] - z);  
			b++;
		}
		count.push_back(min);
		a++;
	}
	min = count[0];
	a = 0;
	while (a < count.size())
	{
		if (count[a] < min)
		{
			min = count[a];
		}
		a++;
	}
	std::cout << min;
	return (0);
}