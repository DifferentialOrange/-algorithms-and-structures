#include <vector>
#include <string>
#include <algorithm>

unsigned Levenshtein_distance(const std::string &string1, const std::string &string2)
{
	std::vector<unsigned> current_level(string1.size() + 1);
	std::vector<unsigned> upper_level(string1.size() + 1);

	for (unsigned i = 0; i < string1.size() + 1; i++)
		upper_level[i] = i;

	for (unsigned j = 1; j < string2.size() + 1; j++)
	{
		current_level[0] = j;
		for (unsigned i = 1; i < string1.size() + 1; i++)
			current_level[i] = std::min({current_level[i - 1] + 1, upper_level[i] + 1,
										upper_level[i - 1] + (string1[i - 1] != string2[j - 1])});
		std::swap(current_level, upper_level);
	}

	return upper_level[string1.size()];
}