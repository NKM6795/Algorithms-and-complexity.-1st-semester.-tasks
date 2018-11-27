#include "Tree.h"


Tree::Tree(int dimension) : dimension(dimension)
{
	tree.resize(10000, minValue);
}


void Tree::insert(int value, int index)
{
	int newIndex = index * dimension + dimension / 2 + 1;

	if (tree[index] >= value)
	{
		while (tree[newIndex] != minValue && value <= tree[newIndex] && newIndex < (index + 1) * dimension)
		{
			++newIndex;
		}
		if (tree[newIndex] == minValue)
		{
			tree[newIndex] = value;
		}
		else
		{
			insert(value, newIndex);
		}
	}
	else
	{
		--newIndex;

		while (tree[newIndex] != minValue && value >= tree[newIndex] && newIndex > index * dimension + 1)
		{
			--newIndex;
		}
		if (tree[newIndex] == minValue)
		{
			tree[newIndex] = value;
		}
		else
		{
			insert(value, newIndex);
		}
	}
}


void Tree::insert(int value)
{
	int index = 0;
	if (tree[index] == minValue)
	{
		tree[index] = value;
	}
	else
	{
		insert(value, index);
	}
}


int Tree::extractMax(int index)
{
	int tempMax = minValue;

	int newIndex = index * dimension + dimension / 2;

	while (tree[newIndex] != minValue && newIndex > index * dimension + 1)
	{
		--newIndex;
	}

	if (newIndex == index * dimension + dimension / 2 && tree[newIndex] == minValue)
	{
		return tree[index];
	}
	else
	{
		return extractMax(newIndex);
	}
}


void Tree::increaseKey(int oldKey, int newKey)
{
	vector<int> newTree = tree;

	tree.clear();
	tree.resize(10000, minValue);

	for (int i = 0; i < int(newTree.size()); ++i)
	{
		if (newTree[i] != minValue && newTree[i] == oldKey)
		{
			insert(newKey);
		}
		else if (newTree[i] != minValue)
		{
			insert(newTree[i]);
		}
	}
}


void Tree::coutTree()
{
	for (int i = 0; i < int(tree.size()); ++i)
	{
		cout << '{';
		if (tree[i] != minValue)
		{
			cout << tree[i];
		}
		cout << "} ";
	}
	cout << '\n';
}
