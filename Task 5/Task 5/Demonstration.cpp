#include "Demonstration.h"


void checkerForUser()
{
	cout << "Please enter count requests\n";

	int number;
	cin >> number;

	
	size_t dim, dimForTransition;
	string type;

	for (int i = 0; i < number; ++i)
	{
		cout << "Please enter matrix dimension\n";
		cin >> dim;
		
		cout << "Please enter matrix type(int, long, short, float, double)\n";
		cin >> type;


		cout << "Dimension for transition, Result:\n";
		for (size_t j = dim; j > 0; --j)
		{
			dimForTransition = j;

			cout << j << " ";

			if (type == "int")
			{
				cout << getWorkTime<int>(dim, dimForTransition) << " seconds\n";
			}
			else if (type == "float")
			{
				cout << getWorkTime<float>(dim, dimForTransition) << " seconds\n";
			}
			else if (type == "double")
			{
				cout << getWorkTime<double>(dim, dimForTransition) << " seconds\n";
			}
			else if (type == "short")
			{
				cout << getWorkTime<short>(dim, dimForTransition) << " seconds\n";
			}
			else if (type == "long")
			{
				cout << getWorkTime<long>(dim, dimForTransition) << " seconds\n";
			}
		}
	}
	cin.get();
}

void checkerForDemonstration()
{
	size_t number = 10;
	size_t offset = 50;

	vector<vector<float> > time(number + 1, vector<float>(number + 1, -1.f));

	for (size_t i = 1; i <= number; ++i)
	{
		size_t dim = i;
		
		for (size_t j = 1; j <= i; ++j)
		{
			size_t dimForTransition = j;

			cout << "Dimension: " << offset + dim << ", Dimension for transition: " << offset + dimForTransition << '\n';
			time[i][j] = getWorkTime<int>(offset + dim, offset + dimForTransition);
			cout << "Result: " << time[i][j] << " seconds\n";
		}
	}

	cout << "Dimension for transition:\n";
	for (size_t i = 1; i <= number; ++i)
	{
		cout << '\t' << offset + i;
	}
	cout << '\n';
	for (size_t i = 1; i <= number; ++i)
	{
		cout << "Dim: " << offset + i << " ";
		for (size_t j = 1; j <= number; ++j)
		{
			cout << time[i][j] << '\t';
		}
		cout << '\n';
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