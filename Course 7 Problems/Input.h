#pragma once
#include <iostream>

namespace Input
{
	int ReadInteger(std::string message)
	{
		int num;

		std::cout << message << std::endl;
		std::cin >> num;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter a Number!!" << std::endl;
			std::cin >> num;
		}
		return num;
	}
	int ReadFloat(std::string message)
	{
		float num;

		std::cout << message << std::endl;
		std::cin >> num;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter a Number!!" << std::endl;
			std::cin >> num;
		}
		return num;
	}
	int ReadDouble(std::string message)
	{
		double num;

		std::cout << message << std::endl;
		std::cin >> num;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter a Number!!" << std::endl;
			std::cin >> num;
		}
		return num;
	}
	int ReadIntegerInRange(std::string message,int from, int to)
	{
		int num;
		do
		{
			num = ReadInteger(message);
		} while (num < from || num > to);
		return num;
	}
}