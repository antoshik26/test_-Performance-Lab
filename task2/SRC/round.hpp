#ifndef ROUND_HPP
#define ROUND_HPP
#include <iostream>
#include <fstream>
#include <map>
#include <cmath>

class round_chech
{
	private:
		std::pair<float, float> coordinates_round;
		float radius;
	public:
		round_chech(std::string _file)
		{
			std::ifstream file_2(_file);
			std::string s;
			std::string s2;
			size_t i = 0;
			
			getline(file_2, s);
			while (i < s.length())
			{
				if (s[i] == ' ')
				{
					s2 = s.substr(0, i);
					break;
				}
				i++;
			}
			coordinates_round.first = atoi(s2.c_str());
			i++;
			s2 = s.substr(i, s.length() - i);
			coordinates_round.second = atoi(s2.c_str());
			getline(file_2, s);
			radius = atoi(s.c_str());
		}

		~round_chech()
		{}

		int check_coordinates(std::pair<float, float> coordinates)
		{
			float result = 0;
			result = sqrt((coordinates_round.first - coordinates.first) * (coordinates_round.first - coordinates.first) + (coordinates_round.second - coordinates.second) * (coordinates_round.first - coordinates.second));
			if (result < radius)
				return (1);
			if (result > radius)
				return (2);
			if (result == radius)
				return (0);
			return (0);
		}

		std::pair<float, float> slit_line(std::string line)
		{
			std::pair<float, float> coordinates;
			std::string s;
			std::string s2;
			size_t i = 0;

			while (i < line.length())
			{
				if (line[i] == ' ')
				{
					s2 = line.substr(0, i);
					break;
				}
				i++;
			}
			coordinates.first = atoi(s2.c_str());
			i++;
			s2 = line.substr(i, line.length() - i);
			coordinates.second = atoi(s2.c_str());
			return (coordinates);
		}
};

#endif