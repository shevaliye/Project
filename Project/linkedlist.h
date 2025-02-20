#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#define SIZE 256
#define SYBM_SIZE 8
typedef struct Node {
	unsigned char symb;
	unsigned char isSymb;
	unsigned int freq;
	struct Node* left, * right, * next;
}Node;

Node* newNode(char symbol, int frequent);

typedef struct Linkedlist
{
	Node* head = nullptr;
	Node* tail = nullptr;
	void push(Node* node);
	void print();
};

typedef union bit2char {
	char symb;
	struct bit {
		unsigned b1 : 1;
		unsigned b2 : 1;
		unsigned b3 : 1;
		unsigned b4 : 1;
		unsigned b5 : 1;
		unsigned b6 : 1;
		unsigned b7 : 1;
		unsigned b8 : 1;
	}mbit;
}BIT2CHAR;
char decode(Node** root, char c);
void printCodes(struct Node* root, std::string arr, std::string codes[SIZE]);
Node* MakeNodeFromNode(Node* left, Node* right);
Node* MakeTreeFromList(Node* head);
void add2list(Node** pphead, Node* ppres);





