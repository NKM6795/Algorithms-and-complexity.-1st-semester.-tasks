#include "SortingCheck.h"


bool sortingCheck(vector<int> &first, vector<int> &second)
{
	if (first.size() != second.size())
	{
		return false;
	}

	arraySorting(first, second);

	for (int i = 0; i < int(first.size()); ++i)
	{
		if (first[i] != second[i])
		{
			return false;
		}
	}
	return true;
}