#include "Algorithms.h"


const int power = 31;
const int alphabet = 26;

vector<int> RabinKarp(string first, string second)
{
	vector<int> result;

	vector<long long> powers(max(first.size(), second.size()));
	powers[0] = 1;
	for (int i = 1; i < int(powers.size()); ++i)
	{
		powers[i] = powers[i - 1] * power;
	}

	vector<long long> secondHashes(second.size());
	for (int i = 0; i < int(second.size()); ++i)
	{
		secondHashes[i] = (second[i] - 'a' + 1) * powers[i];
		if (i != 0)
		{
			secondHashes[i] += secondHashes[i - 1];
		}
	}

	long long firstHash = 0;
	for (int i = 0; i < int(first.size()); ++i)
	{
		firstHash += (first[i] - 'a' + 1) * powers[i];
	}

	for (int i = 0; int(first.size()) - 1 + i < int(second.size()); ++i)
	{
		long long currentHash = secondHashes[int(first.size()) - 1 + i];
		if (i != 0)
		{
			currentHash -= secondHashes[i - 1];
		}

		if (currentHash == firstHash * powers[i])
		{
			result.push_back(i);
		}
	}
	return result;
}

vector<int> naive(string first, string second)
{
	vector<int> result;

	int firstNumber = int(first.size()),
		secondNumber = int(second.size());

	for (int i = 0; i < secondNumber - firstNumber; ++i)
	{
		int j = 0;
		while (first[j] == second[i + j] && j < firstNumber && i + j < secondNumber)
		{
			++j;
		}
		if (j == firstNumber)
		{
			result.push_back(i);
		}
	}

	return result;
}


vector<int> prefixFunction(string first)
{
	int number = int(first.size());

	vector<int> result(number, 0);
	for (int i = 1; i < number; ++i)
	{
		int j = result[i - 1];
		while (j > 0 && first[i] != first[j])
		{
			j = result[j - 1];
		}

		if (first[i] == first[j])
		{
			++j;
		}

		result[i] = j;
	}

	return result;
}

vector<int> kmp(string first, string second)
{
	int firstNumber = int(first.size()),
		secondNumber = int(second.size());

	string forPrefixFunction = first + "#" + second;
	int number = int(forPrefixFunction.size());

	vector<int> result;
	vector<int> p = prefixFunction(forPrefixFunction);

	for (int j = 0; j < secondNumber; ++j)
	{
		if (p[firstNumber + j + 1] == firstNumber)
		{
			result.push_back(j - firstNumber + 1);
		}
	}

	return result;
}


vector<int> getShifts(string first)
{
	vector<int> result(alphabet, first.size() + 1);

	for (int i = 0; i < int(first.size()); ++i)
	{
		result[first[i] - 'a'] = int(first.size()) - i;
	}

	return result;
}

vector<int> BoyerMooreHorspool(string first, string second)
{
	vector<int> shifts = getShifts(first);

	int firstNumber = int(first.size()),
		secondNumber = int(second.size());

	int shift = 0;

	while (shift + firstNumber <= secondNumber)
	{
		int i = firstNumber - 1;
		while (i >= 0 && first[i] == second[shift + i])
		{
			--i;
		}

		if (i < 0)
		{
			return { shift };
		}
		else if (shift + firstNumber < secondNumber)
		{
			shift += shifts[second[shift + firstNumber] - 'a'];
		}
		else
		{
			break;
		}
	}
	return {};
}


vector<int> getSuffixShift(string first)
{
	int number = int(first.size());

	vector<int> result(number + 1, number);
	vector<int> z(number, 0);

	for (int j = 1, maxZidx = 0, maxZ = 0; j < number; ++j)
	{
		if (j <= maxZ)
		{
			z[j] = min(maxZ - j + 1, z[j - maxZidx]);
		}

		while (j + z[j] < number && first[number - 1 - z[j]] == first[number - 1 - (j + z[j])])
		{
			z[j]++;
		}

		if (j + z[j] - 1 > maxZ)
		{
			maxZidx = j;
			maxZ = j + z[j] - 1;
		}
	}

	for (int j = number - 1; j > 0; --j)
	{
		result[number - z[j]] = j;
	}

	for (int j = 1, r = 0; j <= number - 1; ++j)
	{
		if (j + z[j] == number)
		{
			for (; r <= j; ++r)
			{
				if (result[r] == number)
				{
					result[r] = j;
				}
			}
		}
	}

	return result;
}

vector<int> BoyerMoore(string first, string second)
{
	vector<int> suffixShift = getSuffixShift(first);

	int firstNumber = int(first.size()),
		secondNumber = int(second.size());

	for (int i = 0, j = 0; i <= secondNumber - firstNumber && j >= 0; i += suffixShift[j + 1])
	{
		for (j = firstNumber - 1; j >= 0 && first[j] == second[i + j]; --j);
		{
			if (j < 0)
			{
				return { i };
			}
		}
	}
	return {};
}