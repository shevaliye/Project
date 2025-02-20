#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linkedlist.h"
#include <iostream>
#include <fstream>
#include <string>
#define SIZE 256
#define SYBM_SIZE 8
#define BIT8 8

int main()
{
	int freq[SIZE] = { 0 };
	FILE* fr = fopen("input.txt", "rb");
	if (!fr)
		return 0;
	fseek(fr, 0L, SEEK_END);
	long length = ftell(fr);
	fseek(fr, 0, SEEK_SET);
	for (long i = 0; i < length; i++)
	{
		freq[(unsigned char)fgetc(fr)]++;
	}

	Linkedlist list;
	fseek(fr, 0, SEEK_SET);
	for (long i = 0; i < length; i++)
	{
		char x = fgetc(fr);
		if (freq[(unsigned char)x] != 0)
		{
			list.push(newNode(x, freq[(unsigned char)x]));
			freq[(unsigned char)x] = 0;
		}
	}

	std::string arr;
	std::string str;
	std::string codes[SIZE];
	Node koren;
	Node* root = &koren;
	root = MakeTreeFromList(list.head);
	printCodes(root, arr,codes);

}