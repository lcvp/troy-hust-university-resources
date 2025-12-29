#include "hashtab.h"

int HashTable::hashfunc(int value)
{
	return (value % N + N) % N;
}

void HashTable::add(int value)
{
	int index = hashfunc(value);
	L[index].insertItemAtEnd(value);
}

void HashTable::remove(int value)
{
	int index = hashfunc(value);
	L[index].deleteItem(value);
}

bool HashTable::search(int value)
{
	int index = hashfunc(value);
	return L[index].searchItem(value);
}