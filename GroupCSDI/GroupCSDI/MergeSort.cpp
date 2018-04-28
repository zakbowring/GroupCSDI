#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include "MergeSort.h"

MergeSort::MergeSort() {

}

MergeSort::~MergeSort()
{
}


int MergeSort::Run(Node *&headNode) {
	//when testing this only 1040 words can be correctly pasted into the console window.
	//Node* headNode = NULL;

	receiveLinkedList(headNode);
	mergeSort(headNode);
	cout << "Sorted List:";
	displayLinkedList(headNode);
	cout << endl;

	return 0;
}
void MergeSort::mergeSort(Node *&head) {
	if (head->next != NULL)				//check the condition if this is the last node, do nothing
	{
		Node* head1 = 0;
		Node* head2 = head;				//assign head to head 2. Head 2 will point to second half of the linked list
		int len = getLength(head);
		for (int i = 0; i<len / 2; i++)		//use for loop to increment the pointer 2 to the mid poin in linked list
		{
			head1 = head2;				// assign head1 to any node head2 point to, 
			head2 = head2->next;		//in order to put NULL terminate for the first half of the linked list
		}
		head1->next = NULL;				//terminate first half of the linked list
		head1 = head;					//reposition head1 to the beginning of linked list, also the first node of the first half
		mergeSort(head1);
		mergeSort(head2);
		head = merge(head1, head2);
	}
}

Node* MergeSort::merge(Node *&head1, Node *&head2) {
	Node* newHead;
	//Base case: return the other half if  one of them is NULL
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;

	//compare the value
	if (head1->data < head2->data) {
		newHead = head1;							//assign the newHead to the Node has smaller value
		newHead->next = merge(head1->next, head2);	//recall the functionto find the next Node
	}
	else {
		newHead = head2;
		newHead->next = merge(head1, head2->next);
	}

	return newHead;
}

void MergeSort::displayLinkedList(Node *head) {
	Node* current = head;
	for (; current != NULL; current = current->next) {
		cout << current->data << " ";
	}
}
int MergeSort::getLength(Node *head) {
	Node* current = head;
	int i = 0;
	for (; current != NULL; current = current->next) {
		i++;
	}
	return i;
}

void MergeSort::receiveLinkedList(Node *&head) {
	//stringstream ss;
	//string input;
	Node* thisNode = new Node;
	Node* lastNode = 0;
	head = thisNode;

	//cout << "Enter number to be sorted: ";
	//getline(cin, input);
	//ss << input;

	while (thisNode->data) {
		lastNode = thisNode;					//keep track of the last Node
		thisNode->next = new Node;			//Create new Node and link it to the previous Node
		thisNode = thisNode->next;				//increment to the next Node
	}
	lastNode->next = NULL;					//assign NULL to the lastNode's next
	delete thisNode;							//delete pointer but I'm not sure if we need this. I remember function will delete all local variable
}