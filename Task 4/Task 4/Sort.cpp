#include "Sort.h"


void sort(vector<pair<bool, short> > &first)
{
	vector<short> values(4 * SHRT_MAX, 0);

	for (int i = 0; i < int(first.size()); ++i)
	{
		++values[first[i].first * 2 * SHRT_MAX + SHRT_MAX + first[i].second];
	}
	
	first.clear();

	for (long i = 0; i < 4 * SHRT_MAX; ++i)
	{
		while (values[i] > 0)
		{
			first.push_back({ (i > 2 * SHRT_MAX), short(i - SHRT_MAX - 2 * SHRT_MAX * (i > 2 * SHRT_MAX)) });
			--values[i];
		}
	}
}