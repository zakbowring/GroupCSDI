#pragma once
#include "Node.h"
class MergeSort
{
public:

	MergeSort();
	~MergeSort();
	int Run();
	void mergeSort(Node *&head);
	// sorts the link list pointed to by head 
	// precondition: head points to a linked list of items
	// postcondition: head points to a sorted linked list, containing the items
	// that were in the original linked list, but in sorted order

	Node* merge(Node *&head1, Node *&head2);
	// returns a pointer to a sorted linked list that results from merging the sorted 
	// linked lists pointed to by head1 and head2
	// preconditions: head1 and head2 point to sorted linked lists
	// postconditions: returns a pointer to a sorted linked list containing the nodes
	// that used to be in the sorted linked lists pointed to by head1 and head2; 
	// head1 and head2 are NULL

	int getLength(Node *head);
	//return a length of a linked list pointed to by head
	//precondition: head point to a linked list
	//postcondition: none
	void displayLinkedList(Node *head);
	//cout each element in linked list pointed to by head
	//precondition: head point to a linked list
	//postcondition: none
	void receiveLinkedList(Node *&head);
	//receive the input from user using stringstream, and store each element into a node
	//each node is linked together become a linked list with head point to the first node, and the last node's next point to NULL
	//precondition: need a Node pointer to pass in the function
	//postcondition: a Node pointer point to the first Node of the linked list
private:
	Node * head;
};

