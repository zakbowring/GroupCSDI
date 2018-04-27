#pragma once
#include <string>

using namespace std;

class Node
{
public:
	Node();
	~Node();
	string data[2];
	Node* next;
};
