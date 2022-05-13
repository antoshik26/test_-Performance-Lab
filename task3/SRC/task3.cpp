#include <iostream>
#include <fstream>
#include "json.hpp"

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cout << "error: invalid number of arguments" << std::endl;
		return (-1);
	}
	std::ifstream file_1(argv[1]);
	std::ifstream file_2(argv[2]);
	if (!file_1 || !file_2)
	{
		std::cout << "error: invalid arguments" << std::endl;
		return (-1);
	}
	nlohmann::json values;
	file_2 >> values;
	nlohmann::json id = values["values"];
	std::string a;
	std::string line;
	while (getline (file_1,line))
	{
		a = a + line + "\n";
	}
	size_t i = 0;
	size_t j = 0;
	for (auto it = id.begin(); it != id.end(); ++it)
	{
		nlohmann::json b = *it;
		i = a.find("\"value\"", j);
		if (i != std::string::npos)
		{
			a.insert(i + 10, b.at("value"));
		}
		j = i + 1;
	}
	std::ofstream file_3("result.json");
	file_3 << std::setw(4) << a << std::endl;
	return (0);
}