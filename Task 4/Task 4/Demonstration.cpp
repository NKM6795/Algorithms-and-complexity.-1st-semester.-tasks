#include "Demonstration.h"


void checkerForUser()
{
	cout << "Please enter count requests\n";

	int number;
	cin >> number;

	vector<pair<bool, short> > first, second;

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
			cin >> first[j].first >> first[j].second;
		}

		second.clear();
		second.resize(countOfElement);
		
		cout << "Please enter second array\n";
		for (int j = 0; j < countOfElement; ++j)
		{
			cin >> second[j].first >> second[j].second;
		}

		cout << "Result:\n" << sortingCheck(first, second) << '\n';
	}
	cin.get();
}

void checkerForDemonstration()
{
	for (int i = 1; i < 50; ++i)
	{
		vector<pair<bool, short> > first, second;
		for (int j = 0; j < i; ++j)
		{
			first.push_back({ rand() % 2, j });
		}

		second = first;
		sort(second.begin(), second.end());
		random_shuffle(first.begin(), first.end());

		cout << "First array:\n";
		for (int j = 0; j < i; ++j)
		{
			cout << "{" << first[j].first << ", " << first[j].second << "} ";
		}
		cout << "\nSecond array:\n";
		for (int j = 0; j < i; ++j)
		{
			cout << "{" << second[j].first << ", " << second[j].second << "} ";
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