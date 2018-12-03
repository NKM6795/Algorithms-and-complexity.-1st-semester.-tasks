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

		cout << "Result:\n";
		checker(first, second);
	}
	cin.get();
}

void checkerForDemonstration()
{
	for (int i = 10000000; i < 10000050; ++i)
	{
		string first, second;
		for (int j = 0; j < i; ++j)
		{
			second.push_back((char)(97 + rand() % 26));
		}

		int offset = rand() % i;
		int length = rand() % 2 ? 1 + rand() % (i - offset) : 1 + rand() % (1 + (1 + rand() % (i - offset)) / 20);
		first = second.substr(offset, length);

		//cout << "First string: " << first << '\n';
		//cout << "Second string: " << second << '\n';
		cout << "First string: ...\n";
		cout << "Second string: ...\n";
		cout << "Expected result: " << true << '\n';
		cout << "Result:\n";
		checker(first, second);
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