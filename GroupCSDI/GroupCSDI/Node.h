#pragma once
#include <string>

using namespace std;

class Node
{
public:
	Node();
	~Node();

	//To convert from string to integer you can take the value of the first letter in the string and convert to ASCII or something like that
	//When can use this value to act as the integer place holder 

	string data[2];
	int item;
	Node* next;
};
