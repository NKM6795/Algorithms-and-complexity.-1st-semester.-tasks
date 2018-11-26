#include "Demonstration.h"


void checkerForUser()
{
	cout << "Please enter count requests\n";

	int number;
	cin >> number;

	vector<int> first, second;

	for (int i = 0; i < number; ++i)
	{
		int countOfElement;
		cout << "Please enter count of element\n";
		cin >> countOfElement;
		
		first.clear();
		first.resize(countOfElement);

		cout << "Please enter first array\n";
		for (int j = 0; j < countOfElement; ++j)
		{
			cin >> first[j];
		}

		second.clear();
		second.resize(countOfElement);
		
		cout << "Please enter second array\n";
		for (int j = 0; j < countOfElement; ++j)
		{
			cin >> second[j];
		}

		cout << "Result:\n" << sortingCheck(first, second) << '\n';
	}
	cin.get();
}

void checkerForDemonstration()
{
	for (int i = 1; i < 50; ++i)
	{
		vector<int> first, second;
		for (int j = 0; j < i; ++j)
		{
			first.push_back(j);
		}

		random_shuffle(first.begin(), first.end());

		second = first;
		random_shuffle(second.begin(), second.end());
		
		cout << "First array:\n";
		for (int j = 0; j < i; ++j)
		{
			cout << first[j] << ' ';
		}
		cout << "\nSecond array:\n";
		for (int j = 0; j < i; ++j)
		{
			cout << second[j] << ' ';
		}
		cout << "\nResult: " << sortingCheck(first, second) << '\n';
	}
	cin.get();
	cin.get();
}

void demonstration()
{
	cout << "-1 - exit\n0 - user\n1 - demonstration\n";
	int massage;
	cin >> massage;

	if (massage == 0)
	{
		checkerForUser();
	}
	else if (massage == 1)
	{
		checkerForDemonstration();
	}
}