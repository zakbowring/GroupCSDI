#include "stdafx.h"
#include "LinkedList.h"

using namespace std;


LinkedList::LinkedList()
{
	
}


LinkedList::~LinkedList(void)
{
	Node* currNode = head, *nextNode = NULL;
	while (currNode != NULL)
	{
		nextNode = currNode->next;
		//destroy the current node
		delete currNode;
		currNode = nextNode;
	}
}

Node* LinkedList::InsertNode(int index, string x[2])
{
	if (index < 0) return NULL;

	int currIndex = 1;
	Node* currNode = head;
	while (currNode&&index > currIndex) {
		currNode = currNode->next;
		currIndex++;
	}
	if (index > 0 && currNode == NULL)return NULL;

	Node* newNode = new Node;
	for (int i = 0; i < 2; i++)
	{
		newNode->data[i] = x[i];
	}
	if (index == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	return newNode;
}

int LinkedList::FindNode(string x[2]) {
	Node* currNode = head;
	int currIndex = 1;
	while (currNode&&currNode->data != x) {
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode) return currIndex;
	return 0;
}

//int LinkedList::DeleteNode(string x[]) {
//	Node* prevNode = NULL;
//	Node* currNode = head;
//	int  currIndex = 1;
//	while (currNode&&currNode->data != x) {
//		prevNode = currNode;
//		currNode = currNode->next;
//		currIndex++;
//	}
//	if (currNode) {
//		if (prevNode) {
//			prevNode->next = currNode->next;
//			delete currNode;
//		}
//		else
//		{
//			head = currNode->next;
//			delete currNode;
//		}
//		return currIndex;
//	}
//	return 0;
//}

void LinkedList::DisplayList() {
	int num = 0;
	Node* currNode = head;
	while (currNode != NULL) {
		for (int i = 0; i < 2; i++)
		{
			cout << currNode->data[i] << endl;
		}
		currNode = currNode->next;
		num++;
	}
	cout << "Number of nodes in the list: " << num << endl;
}


//Have a pointer to the start of the list
void LinkedList::sort()
{
	struct node {
		int data;
		node *next;
	};

	node *head;
	int count = 0, i;
	node *start = head;
	node *current = NULL;
	node *tail = NULL;
	node *temp = NULL;

	while (start != NULL) { //grab count
		count++;
		start = start->next;
	}

	for (i = 0; i<count; ++i) { //for every element in the list

		current = tail = head; //set curr and trail at the start node

		while (current->next != NULL) { //for the rest of the elements in the list
			if (current->data > current->next->data) { //compare curr and curr->next

				temp = current->next; //swap pointers for curr and curr->next
				current->next = current->next->next;
				temp->next = current;

				//now we need to setup pointers for trail and possibly head
				if (current == head) //this is the case of the first element swapping to preserve the head pointer
					head = tail = temp;
				else //setup trail correctly
					tail->next = temp;
				current = temp; //update curr to be temp since the positions changed
			}
			//advance pointers
			tail = current;
			current = current->next;
		}
	}
}