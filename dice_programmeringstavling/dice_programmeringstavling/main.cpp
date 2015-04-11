#include <iostream>
#include "ReadTextFile.h"

int main() 
{
	std::vector < std::string > vector;
	int status = textToVector("dice_programmeringstavling\\anagramatic_list.txt", vector);
	std::cout << status << "\n";
	for each(std::string s in vector)
	{
		std::cout << s << "\n";
	}
	return 0;
}