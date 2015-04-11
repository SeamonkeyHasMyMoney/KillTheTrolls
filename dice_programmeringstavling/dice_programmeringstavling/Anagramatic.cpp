#include "Anagramatic.h"
#include "Primes.h"

int getPrime(std::string s)
{
	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		res *= primes[s[i]];
	}
	return res;
}

bool isAnagram(std::string s1, std::string s2)
{
	if (s1.size() != s2.size())
		return false;

	if (getPrime(s1) != getPrime(s2))
		return false;

	return true;
}

int getAnagrams(std::vector<std::string>& anagrams)
{
	
}

