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
		cout << "Please enter first file\n";
		getline(cin, first);

		cout << "Please enter second file\n";
		getline(cin, second);

		cout << "Result:\n" << sortingCheck(first, second) << '\n';
	}
	cin.get();
}

void checkerForDemonstration()
{
	string first = "test.dat", second = "result.dat";
	
	cout << "First file: " << first << '\n';
	cout << "Second file: " << second << '\n';
	cout << "Expected result: " << 1 << '\n';
	cout << "Result: " << sortingCheck(first, second) << '\n';

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