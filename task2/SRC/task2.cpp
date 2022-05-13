#include <iostream>
#include <fstream>
#include <vector>
#include "./round.hpp"

int main(int argc, char** argv)
{
	std::pair<float, float> coordinates;
	std::string line;
 
	if (argc != 3)
	{
		std::cout << "error: invalid number of arguments" << std::endl;
		return (-1);
	}
	std::ifstream file_1 (argv[1]);
	std::ifstream file_2 (argv[2]);
	if (!file_1 || !file_2)
	{
		std::cout << "error: invalid arguments" << std::endl;
		return (-1);
	}
	round_chech check_round(argv[1]);
	while(getline(file_2, line)) 
	{
		coordinates = check_round.slit_line(line);
		switch (check_round.check_coordinates(coordinates))
		{
			case 0:
				std::cout << "точка лежит на окружности" << std::endl;
				break;
			case 1:
				std::cout << "точка внутри" << std::endl;
				break;
			case 2:
				std::cout << "точка снаружи" << std::endl;
				break;
		}
	}
	file_1.close();
	file_2.close();
	return (0);
}