#include "RabinKarpCheck.h"


bool rabinKarpCheck(vector<string> first, vector<string> second)
{
	vector<pair<int, int> > result = RabinKarp(first, second);

	for (int i = 0; i < int(result.size()); ++i)
	{
		cout << '{' << result[i].first << ", " << result[i].second << "} ";
	}
	cout << '\n';
	return false;
}