#include "Anagramatic.h"

bool isAnagram(std::string s)
{
	int halfLength = s.size() / 2;
	for (int i = 0; i < halfLength; i++)
	{
		if (s.at(i) == s.at(s.size() - 1 - i))
			// TODO
	}
}

int getAnagrams(std::vector<std::string>& anagrams)
{
	// TODO get list
	std::vector < std::string > list = { "hej", "anna", "otto", "majs", "jams" };

	for (int i = 0; i < list.size(); i++)
	{
		if (isAnagram(list[i]))
			anagrams.push_back(list[i]);
	}
}

