#include "Tree.h"


int main()
{
	Tree tree;

	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	tree.insert(4);
	tree.insert(0);
	tree.insert(5);
	tree.insert(-2);
	tree.insert(-1);
	tree.insert(-3);
	tree.insert(-4);
	tree.insert(-8);
	cout << tree.extractMax() << '\n';
	tree.increaseKey(5, 10);
	cout << tree.extractMax() << '\n';
	tree.coutTree();
}