#define _CRT_SECURE_NO_WARNINGS 1
#include "hash.h"

void text1(HashTable* ph)
{
	InitHash(ph);
	ScanfHash(ph);
	ShowHash(ph);
}

int main()
{
	HashTable* hash;
	hash = (HashTable*)malloc(sizeof(HashTable));
	text1(hash);
	return 0;
}