#include "Demonstration.h"


void checkerForUser()
{
	cout << "Please enter count requests\n";

	int number;
	cin >> number;

	string first, second;
	getline(cin, first);

	for (int i = 0; i < number; ++i)
	{
		cout << "Please enter first string\n";
		getline(cin, first);
		
		cout << "Please enter second string\n";
		getline(cin, second);

		cout << "Result:\n" << cyclicShiftCheck(first, second) << '\n';
	}
	cin.get();
}

void checkerForDemonstration()
{
	for (int i = 1; i < 50; ++i)
	{
		string first, second;
		for (int j = 0; j < i; ++j)
		{
			first.push_back((char)(97 + rand() % 26));
		}

		int offset = rand() % i;
		second = first.substr(offset) + first.substr(0, offset);

		bool isChanged = false;
		if (rand() % 4 == 0)
		{
			isChanged = true;
			++second[rand() % i];
		}

		cout << "First string: " << first << '\n';
		cout << "Second string: " << second << '\n';
		cout << "Expected result: " << !isChanged << '\n';
		cout << "Result: " << cyclicShiftCheck(first, second) << '\n';
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