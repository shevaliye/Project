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
Node* MakeNodeFromNode(Node* left, Node* right)
{
  Node* res = (Node*)malloc(sizeof(Node));
  res->freq = left->freq + right->freq;
  res->isSymb = 0;
  res->symb = 0;
  res->left = left;
  res->right = right;
  res->next = 0;
  return res;
}
Node* MakeTreeFromList(Node* head)
{
  while (head && head->next)
  {
    Node* left = head;
    Node* right = head->next;
    add2list(&(head->next->next), MakeNodeFromNode(left, right));
    head = head->next->next;
  }
  return head;
}
void add2list(Node** pphead, Node* ppres)
{
  if ((*pphead) == nullptr || (*pphead)->freq > ppres->freq)
  {
    ppres->next = *pphead;
    *pphead = ppres;
  }
  else
  {
    Node* current = *pphead;
    while (current->next != nullptr && current->next->freq <= ppres->freq)
    {
      current = current->next;
    }
    ppres->next = current->next;
    current->next = ppres;
  }
}
char decode(Node** root, char c)
{
	if (c == '0')
	{
		(*root) = (*root)->left;
		if ((*root)->symb)
		{
			return (*root)->symb;
		}
	}
	if (c == '1')
	{
		(*root) = (*root)->right;
		if ((*root)->symb)
		{
			return (*root)->symb;
		}
	}
	return 0;
}

void printCodes(struct Node* root, std::string arr, std::string codes[SIZE])
{
  if (root->left != nullptr)
  {
    printCodes(root->left, arr+'0', codes);
  }
  if (root->right != nullptr) 
  {
    printCodes(root->right, arr+'1', codes);
  }
  if (root->left == nullptr && root->right == nullptr) 
  {
    codes[root->symb] = arr;
  }
}
