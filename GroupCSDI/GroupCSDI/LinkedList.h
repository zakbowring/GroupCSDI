#pragma once
#include "Node.h"
#include <iostream>
#include <string>
class LinkedList
{
public:
	LinkedList(void) { head = NULL; }
	~LinkedList(void);
	void sort();
	bool IsEmpty() { return head == NULL; }
	Node* InsertNode(int index, string x[21]);
	int FindNode(string x[21]);
	int StartUp();
	int DeleteNode(string x[21]);
	void DisplayList(void);

private:
	Node * head;
	

};

