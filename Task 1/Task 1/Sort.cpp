#include "Sort.h"


int getFibonacciNumber(int i, int p)
{
	if (i >= 0 && i < p)
	{
		return 0;
	}
	
	if (i == p)
	{
		return 1;
	}

	int result = 0;
	for (int j = i - 1 - p; j < i; ++j)
	{
		result += getFibonacciNumber(j, p);
	}
	return result;
}


void sort(vector<int> &first)
{
	vector<list<int> > listsForMargeSort(1);
	int index = 0;
	vector<int> buffer;
	int bufferMaxSize = 2;
	bool needFirst = true;
	int minKey = 10000;
	int key = 0;
	int maxOldKey = -10000;

	
	for (int i = 0; i < int(first.size()); ++i)
	{
		buffer.push_back(first[i]);

		key = first[i];

		if (needFirst)
		{
			minKey = min(minKey, buffer.back());

			if (buffer.back() == minKey)
			{
				swap(buffer[buffer.size() - 1], buffer[buffer.size() - 2]);
			}
		}

		if (bufferMaxSize == int(buffer.size()))
		{
			if (needFirst)
			{
				needFirst = false;
			}




			if (maxOldKey < key)
			{
				++index;
				listsForMargeSort.resize(index + 1);
				swap(buffer[0], buffer[1]);
				maxOldKey = key;
			}
					
			listsForMargeSort[index].push_back(buffer.back());
			buffer.pop_back();
		}
		last = min(last, key);
	}

}