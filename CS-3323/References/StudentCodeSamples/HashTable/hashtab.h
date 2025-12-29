#pragma once
#include "LList.h"

const int N = 11;

class HashTable
{
private:
	LList L[N];
	int hashfunc(int);

public:
	void add(int);
	void remove(int);
	bool search(int);
};