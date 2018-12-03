#include "Demonstration.h"


void checkerForUser()
{
	cout << "Please enter count requests\n";

	int number;
	cin >> number;

	vector<string> first(1), second(1);

	for (int i = 0; i < number; ++i)
	{
		int dimention;
		cout << "Please enter first dimention\n";
		cin >> dimention;
		first.resize(dimention);

		getline(cin, first[0]);
		cout << "Please enter first strings\n";
		for (int j = 0; j < dimention; ++j)
		{
			getline(cin, first[j]);
		}
		
		cout << "Please enter second dimention\n";
		cin >> dimention;
		second.resize(dimention);
		cin.get();

		cout << "Please enter second strings\n";
		for (int j = 0; j < dimention; ++j)
		{
			getline(cin, second[j]);
		}

		cout << "Result:\n";
		rabinKarpCheck(first, second);
	}
	cin.get();
}

void checkerForDemonstration()
{
	for (int i = 2; i < 10; ++i)
	{
		vector<string> first, second(i);
		for (int j = 0; j < i; ++j)
		{
			for (int l = 0; l < i; ++l)
			{
				second[j].push_back((char)(97 + rand() % 26));
			}
		}

		int dimention = 1 + rand() % i;
		first.resize(dimention);

		int xOffset = rand() % (int(second.size()) - dimention + 1),
			yOffset = rand() % (int(second.size()) - dimention + 1);

		for (int j = xOffset; j < xOffset + dimention; ++j)
		{
			for (int l = yOffset; l < yOffset + dimention; ++l)
			{
				first[j - xOffset].push_back(second[j][l]);
			}
		}

		
		bool isChanged = false;
		if (rand() % 4 == 0)
		{
			isChanged = true;
			++first[rand() % first.size()][rand() % first.size()];
		}

		cout << "First string:\n";
		for (int j = 0; j < int(first.size()); ++j)
		{
			cout << first[j] << '\n';
		}
		cout << "\nSecond string:\n";
		for (int j = 0; j < int(second.size()); ++j)
		{
			cout << second[j] << '\n';
		}
		cout << "\nExpected result: " << !isChanged << '\n';

		cout << "Result: ";
		rabinKarpCheck(first, second);
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