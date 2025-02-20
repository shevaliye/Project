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





