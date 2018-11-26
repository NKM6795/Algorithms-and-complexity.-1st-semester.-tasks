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

void sort(vector<pair<bool, unsigned char> > &first, int discharge)
{
	bool firstDivision = discharge == -1;
	vector<vector<pair<bool, unsigned char> > > buckets(firstDivision ? 2 : 10);

	for (int i = 0; i < int(first.size()); ++i)
	{
		if (firstDivision)
		{
			if (!first[i].first)
			{
				buckets[0].push_back(first[i]);
			}
			else
			{
				buckets[1].push_back(first[i]);
			}
		}
		else
		{
			buckets[(first[i].second % (discharge * 10)) / discharge].push_back(first[i]);
		}
	}

	for (int i = 0; i < int(buckets.size()) && discharge != 1; ++i)
	{
		sort(buckets[i], firstDivision ? 1000 : discharge / 10);
	}

	vector<pair<bool, unsigned char> > result;

	for (int i = 0; i < int(buckets.size()); ++i)
	{
		for (int j = 0; j < int(buckets[i].size()); ++j)
		{
			result.push_back(buckets[i][j]);
		}
	}

	first = result;
}


bool comparison1(pair<bool, short> left, pair<bool, short> right)
{
	if (left.first < right.first)
	{
		return true;
	}
	return left.second < right.second;
}

bool comparison2(pair<bool, short> left, pair<bool, short> right)
{
	if (left.first > right.first)
	{
		return true;
	}
	return left.second >= right.second;
}

void downHeap(vector<pair<bool, short> > &first, long k, long number)
{
	long child;
	pair<bool, short> newElement = first[k];

	while (k <= number / 2)
	{
		child = 2 * k;

		if (child < number && first[child] < first[child + 1])
		{
			++child;
		}
		if (newElement >= first[child])
		{
			break;
		}
	
		first[k] = first[child];
		k = child;
	}

	first[k] = newElement;
}

void heapSort(vector<pair<bool, short> > &first)
{
	for (int i = int(first.size()) / 2; i >= 0; --i)
	{
		downHeap(first, i, int(first.size()) - 1);
	}

	for (int i = int(first.size()) - 1; i > 0; --i)
	{
		swap(first[i], first[0]);

		downHeap(first, 0, i - 1);
	}
}