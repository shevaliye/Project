#include "linkedlist.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#define SIZE 256
#define SYBM_SIZE 8
Node* newNode(char symbol, int frequent)
{
	Node* node;
	node = (Node*)malloc(sizeof(Node));
	node->symb = symbol;
	node->freq = frequent;
	node->isSymb = 1;
	node->left = node->right = node->next = nullptr;
	return node;
}
void Linkedlist::push(Node* node)
{
	if (head == nullptr)
	{
		head = tail = node;
	}
	else if (head == tail)
	{
		if (node->freq >= head->freq)
		{
			head->next = node;
			tail = node;

		}
		else
		{
			node->next = tail;
			head = node;
		}
	}
	else
	{

		Node* current = head;
		if (node->freq < head->freq)
		{
			node->next = head;
			head = node;
			return;

		}
		if (node->freq >= tail->freq)
		{
			tail->next = node;
			tail = node;
			return;
		}
		while (current->next != nullptr && current->next->freq <= node->freq)
		{
			current = current->next;
		}
		node->next = current->next;
		current->next = node;
	}
}

void Linkedlist::print()
{
	Node* node = head;
	while (node != nullptr)
	{
		printf("%c ", node->symb);
		node = node->next;
	}
}