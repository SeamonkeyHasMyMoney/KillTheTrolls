#include "ReadTextFile.h"
#include <iostream>
#include <fstream>

int textToVector(std::string filename, std::vector<std::string>& list)
{
	list.clear();
	std::ifstream inputTxt;
	std::string line;
	inputTxt.open("C:\\dev\\KillTheTrolls\\dice_programmeringstavling\\dice_programmeringstavling\\anagramtic_list.txt");
	if (inputTxt.is_open())
	{
		while (std::getline(inputTxt, line))
		{
			list.push_back(line);
		}
		inputTxt.close();
		return 0;
	}
	return -1;
}