#include "Checker.h"


bool checker(string first, string second)
{
	clock_t timer;

	//RabinKarp
	{
		timer = clock();

		vector<int> result = RabinKarp(first, second);

		timer = clock() - timer;

		//for (int i = 0; i < int(result.size()); ++i)
		//{
		//	cout << result[i] << ' ';
		//}
		//cout << '\n';

		cout << "RabinKarp: " << float(timer) / CLOCKS_PER_SEC << '\n';
	}

	//Naive
	{
		timer = clock();

		vector<int> result = naive(first, second);

		timer = clock() - timer;

		//for (int i = 0; i < int(result.size()); ++i)
		//{
		//	cout << result[i] << ' ';
		//}
		//cout << '\n';

		cout << "Naive: " << float(timer) / CLOCKS_PER_SEC << '\n';
	}

	//Kmp
	{
		timer = clock();

		vector<int> result = kmp(first, second);

		timer = clock() - timer;

		//for (int i = 0; i < int(result.size()); ++i)
		//{
		//	cout << result[i] << ' ';
		//}
		//cout << '\n';

		cout << "Kmp: " << float(timer) / CLOCKS_PER_SEC << '\n';
	}

	//BoyerMoore
	{
		timer = clock();

		vector<int> result = BoyerMoore(first, second);

		timer = clock() - timer;

		//for (int i = 0; i < int(result.size()); ++i)
		//{
		//	cout << result[i] << ' ';
		//}
		//cout << '\n';

		cout << "BoyerMoore: " << float(timer) / CLOCKS_PER_SEC << '\n';
	}

	//BoyerMooreHorspool
	{
		timer = clock();

		vector<int> result = BoyerMooreHorspool(first, second);

		timer = clock() - timer;

		//for (int i = 0; i < int(result.size()); ++i)
		//{
		//	cout << result[i] << ' ';
		//}
		//cout << '\n';

		cout << "BoyerMooreHorspool: " << float(timer) / CLOCKS_PER_SEC << '\n';
	}

	return false;
}