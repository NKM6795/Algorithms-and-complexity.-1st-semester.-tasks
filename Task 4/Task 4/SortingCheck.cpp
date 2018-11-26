#include "SortingCheck.h"


bool sortingCheck(vector<pair<bool, short> > &first, vector<pair<bool, short> > &second)
{
	if (first.size() != second.size())
	{
		return false;
	}

	sort(first);

	for (int i = 0; i < int(first.size()); ++i)
	{
		if (first[i] != second[i])
		{
			return false;
		}
	}
	return true;
}