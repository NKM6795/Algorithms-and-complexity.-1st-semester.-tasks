#pragma once


#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


class Tree
{
	int minValue = -10000;

	vector<int> tree;
	int dimension;

	void insert(int value, int index);

public:
	Tree(int dimension = 2);

	void insert(int value);

	int extractMax(int index = 0);

	void increaseKey(int oldKey, int newKey);

	void coutTree();
};