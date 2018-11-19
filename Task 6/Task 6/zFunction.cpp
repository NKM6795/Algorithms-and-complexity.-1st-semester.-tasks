#include "zFunction.h"


vector<int> adaptedZFunction(string first, string second)
{
	int number = int(first.size());
	vector<int> z(number, 0);

	for (int i = 1, left = 0, right = 0; i < number; ++i)
	{
		if (i <= right)
		{
			z[i] = min(right - i + 1, z[i - left]);
		}

		while (i + z[i] < number && second[z[i]] == first[i + z[i]])
		{
			++z[i];
		}

		if (i + z[i] - 1 > right)
		{
			left = i;
			right = i + z[i] - 1;
		}
	}
	
	return z;
}