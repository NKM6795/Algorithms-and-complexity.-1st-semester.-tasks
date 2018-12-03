#include "Sort.h"


void sort(string first)
{
	ifstream fileIn(first);


	int maxBuffer = 50;
	list<int> buffer;

	int number;
	fileIn >> number;

	int current;

	int numberA,
		numberB;

	if (number > maxBuffer)
	{
		numberA = ((number / maxBuffer) / 2 + (number / maxBuffer) % 2) * maxBuffer + ((number / maxBuffer) % 2 ? 0 : number % maxBuffer);
		numberB = ((number / maxBuffer) / 2) * maxBuffer + ((number / maxBuffer) % 2 ? number % maxBuffer : 0);
	}
	else
	{
		vector<int> result;
		for (int i = 0; i < number; ++i)
		{
			fileIn >> current;
			result.push_back(current);
		}
		fileIn.close();

		sort(result.begin(), result.end());

		ofstream fileOutResult(first);
		fileOutResult << number << ' ';

		for (int i = 0; i < number; ++i)
		{
			fileOutResult << result[i] << ' ';
		}
		fileOutResult.close();
		return;
	}


	string aFirst = "A" + first,
		bFirst = "B" + first;

	bool inA = true;
	ofstream fileOutA(aFirst),
		fileOutB(bFirst);

	fileOutA << numberA << ' ';
	fileOutB << numberB << ' ';

		
	for (int i = 0; i < number; ++i)
	{
		fileIn >> current;
		buffer.push_back(current);

		if ((i != 0 && i % maxBuffer == 49) || i == number - 1)
		{
			if (inA)
			{
				for (int j = 0; j < maxBuffer && j + (i / maxBuffer) * maxBuffer < number; ++j)
				{
					fileOutA << buffer.back() << ' ';
					buffer.pop_back();
				}
			}
			else
			{
				for (int j = 0; j < maxBuffer && j + (i / maxBuffer) * maxBuffer < number; ++j)
				{
					fileOutB << buffer.back() << ' ';
					buffer.pop_back();
				}
			}
			inA = !inA;
		}
	}

	fileIn.close();
	fileOutA.close();
	fileOutB.close();

	sort(aFirst);
	sort(bFirst);

	ofstream fileOutResult(first);
	ifstream fileInA(aFirst),
		fileInB(bFirst);

	fileOutResult << number << ' ';

	fileInA >> numberA;
	fileInB >> numberB;

	int currentA,
		currentB;

	fileInA >> currentA;
	fileInB >> currentB;

	for (int i = 0, j = 0, k = 0; k < number; ++k)
	{
		if (i > numberA - 1)
		{
			fileOutResult << currentB << ' ';
			j++;
			fileInB >> currentB;
		}
		else if (j > numberB - 1)
		{
			fileOutResult << currentA << ' ';
			i++;
			fileInA >> currentA;
		}
		else if (currentA < currentB)
		{
			fileOutResult << currentA << ' ';
			i++;
			fileInA >> currentA;
		}
		else
		{
			fileOutResult << currentB << ' ';
			j++;
			fileInB >> currentB;
		}
	}

	fileOutResult.close();
	fileInA.close();
	fileInB.close();


	if (remove(aFirst.c_str()))
	{
		
	}

	if (remove(bFirst.c_str()))
	{

	}
}