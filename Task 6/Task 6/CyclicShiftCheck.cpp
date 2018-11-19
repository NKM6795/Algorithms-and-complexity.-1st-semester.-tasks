#include "CyclicShiftCheck.h"


bool cyclicShiftCheck(string first, string second)
{
	if (first.size() != second.size())
	{
		return false;
	}

	vector<int> z = adaptedZFunction(first + first, second);

	for (int i = 0; i < int(z.size()); ++i)
	{
		if (z[i] == int(first.size()))
		{
			return true;
		}
	}
	return false;
}