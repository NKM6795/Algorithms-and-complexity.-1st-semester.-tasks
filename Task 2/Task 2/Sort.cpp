#include "Sort.h"


void arraySorting(vector<int> &first, vector<int> &second)
{
	int number = 0;
	list<pair<bool, int> > checker;
	vector<int> newFirst, newSecond;
	vector<int> tempFirst, tempSecond;

	while (first.size() > 0 || second.size() > 0)
	{
		for (int i = 0, j = 0; i < int(first.size()) || j < int(second.size()); )
		{
			if (number == 0)
			{
				if (i < int(first.size()))
				{
					checker.push_front({ true, first[i] });
					++i;
				}
				else
				{
					checker.push_front({ false, second[j] });
					++j;
				}
				++number;
			}
			else if (checker.front().first && j < int(second.size()) && second[j] <= checker.front().second)
			{
				checker.push_front({ false, second[j] });
				++j;
				++number;
			}
			else if (!checker.front().first && i < int(first.size()) && first[i] <= checker.front().second)
			{
				checker.push_front({ true, first[i] });
				++i;
				++number;
			}
			else if (checker.back().first && j < int(second.size()) && second[j] >= checker.back().second)
			{
				checker.push_back({ false, second[j] });
				++j;
				++number;
			}
			else if (!checker.back().first && i < int(first.size()) && first[i] >= checker.back().second)
			{
				checker.push_back({ true, first[i] });
				++i;
				++number;
			}
			else if (checker.back().first && checker.front().first && j < int(second.size()))
			{
				tempSecond.push_back(second[j]);
				++j;
			}
			else if (!checker.back().first && !checker.front().first && i < int(first.size()))
			{
				tempFirst.push_back(first[i]);
				++i;
			}
			else if (j < int(second.size()))
			{
				tempSecond.push_back(second[j]);
				++j;
			}
			else if (i < int(first.size()))
			{
				tempFirst.push_back(first[i]);
				++i;
			}
		}
		first = tempFirst;
		second = tempSecond;
		tempFirst.clear();
		tempSecond.clear();

		auto i = checker.begin(),
			j = checker.begin();
		++j;
		while (number > 1 && (*i).second == (*j).second)
		{
			newFirst.push_back((*i).second);
			newSecond.push_back((*j).second);

			if (number > 3)
			{
				++i;
				++i;
				++j;
				++j;
			}
			checker.pop_front();
			checker.pop_front();
			number -= 2;
		}

		if (number > 1)
		{
			i = checker.end();
			--i;
			j = checker.end();
			--j;
			--j;
			while (number > 1 && (*i).second == (*j).second)
			{
				newFirst.push_back((*i).second);
				newSecond.push_back((*j).second);

				if (number > 3)
				{
					--i;
					--i;
					--j;
					--j;
				}
				checker.pop_back();
				checker.pop_back();
				number -= 2;
			}
		}
	}
	first = newFirst;
	second = newSecond;
}