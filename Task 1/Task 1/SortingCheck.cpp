#include "SortingCheck.h"


bool sortingCheck(string first, string second)
{
	sort(first);

	ifstream fileIn0(first),
		fileIn1(second);

	int firstNumber,
		secondNumber;

	fileIn0 >> firstNumber;
	fileIn1 >> secondNumber;

	for (int i = 0; i < firstNumber; ++i)
	{
		int firstValue,
			secondValue;
		
		fileIn0 >> firstValue;
		fileIn1 >> secondValue;

		if (firstValue != secondValue)
		{
			fileIn0.close();
			fileIn1.close();
			return false;
		}
	}
	fileIn0.close();
	fileIn1.close();
	return true;
}