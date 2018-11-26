#pragma once


#include <vector>
#include <list>
#include <algorithm>
#include <limits.h>


using namespace std;


void sort(vector<pair<bool, short> > &first);

void sort(vector<pair<bool, unsigned char> > &first, int discharge = -1);

bool comparison1(pair<bool, short> left, pair<bool, short> right);

bool comparison2(pair<bool, short> left, pair<bool, short> right);

void downHeap(vector<pair<bool, short> > &first, long k, long number);

void heapSort(vector<pair<bool, short> > &first);