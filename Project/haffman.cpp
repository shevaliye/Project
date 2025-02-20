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
	BIT2CHAR symb;
	Node koren;
	Node* root = &koren;
	root = MakeTreeFromList(list.head);
	printCodes(root, arr, codes);
	fseek(fr, 0, SEEK_SET);
	for (long i = 0; i < length; i++)
	{
		str += codes[fgetc(fr)];
	}

	int count = str.length() / BIT8;
	int tail = (BIT8 - (str.length() % BIT8)) % BIT8;
	int len;
	if (tail == 0)
	{
		len = count;
	}
	else
	{
		len = count + 1;
	}
	for (int i = 0; i < tail; i++)
	{
		str += '0';
	}
	//std::cout << str.length()<< std::endl;

	std::string res;
	for (int i = 0; i < len; i++)
	{
		symb.mbit.b1 = str[i * BIT8 + 0];
		symb.mbit.b2 = str[i * BIT8 + 1];
		symb.mbit.b3 = str[i * BIT8 + 2];
		symb.mbit.b4 = str[i * BIT8 + 3];
		symb.mbit.b5 = str[i * BIT8 + 4];
		symb.mbit.b6 = str[i * BIT8 + 5];
		symb.mbit.b7 = str[i * BIT8 + 6];
		symb.mbit.b8 = str[i * BIT8 + 7];
		res += symb.symb;
	}
	//std::cout << len << std::endl;
	//std::cout << res.length();

	std::string fw = "output.txt";
	std::ofstream outFile(fw, std::ios::binary);
	outFile << res;
	outFile.close();

}