#include "RabinKarp.h"

const int power = 31;

vector<pair<int, int> > RabinKarp(vector<string> first, vector<string> second)
{
	vector<pair<int, int> > result;
	
	vector<long long> powers(max(first.size(), second.size()) * max(first.size(), second.size()));
	powers[0] = 1;
	for (int i = 1; i < int(powers.size()); ++i)
	{
		powers[i] = powers[i - 1] * power;
	}

	vector<vector<long long>> secondHashes(second.size(), vector<long long>(second.size()));
	for (int i = 0; i < int(second.size()); ++i)
	{
		for (int j = 0; j < int(second.size()); ++j)
		{
			secondHashes[i][j] = (second[i][j] - 'a' + 1) * powers[i * int(second.size()) + j];
			if (i != 0)
			{
				secondHashes[i][j] += secondHashes[i - 1][j];
			}
			if (j != 0)
			{
				secondHashes[i][j] += secondHashes[i][j - 1];
			}
			if (i != 0 && j != 0)
			{
				secondHashes[i][j] -= secondHashes[i - 1][j - 1];
			}
		}
	}

	long long firstHash = 0;
	for (int i = 0; i < int(first.size()); ++i)
	{
		for (int j = 0; j < int(first.size()); ++j)
		{
			firstHash += (first[i][j] - 'a' + 1) * powers[i * int(second.size()) + j];
		}
	}

	for (int i = 0; int(first.size()) - 1 + i < int(second.size()); ++i)
	{
		for (int j = 0; int(first.size()) - 1 + j < int(second.size()); ++j)
		{
			long long currentHash = secondHashes[int(first.size()) - 1 + i][int(first.size()) - 1 + j];
			if (i != 0)
			{
				currentHash -= secondHashes[i - 1][int(first.size()) - 1 + j];
			}
			if (j != 0)
			{
				currentHash -= secondHashes[int(first.size()) - 1 + i][j - 1];
			}
			if (i != 0 && j != 0)
			{
				currentHash += secondHashes[i - 1][j - 1];
			}
			
			if (currentHash == firstHash * powers[i * int(second.size()) + j])
			{
				result.push_back({ i, j });
			}
		}
	}
	return result;
}