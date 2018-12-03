#pragma once


#include <algorithm>
#include <vector>
#include <string>
#include <iostream>


using namespace std;


vector<int> RabinKarp(string first, string second);

vector<int> naive(string first, string second);


vector<int> prefixFunction(string first);

vector<int> kmp(string first, string second);


vector<int> getShifts(string first);

vector<int> BoyerMooreHorspool(string first, string second);


vector<int> getSuffixShift(string first);

vector<int> BoyerMoore(string first, string second);