#include "stdafx.h"
#include "LinkedList.h"


LinkedList::LinkedList()
{
	
}


LinkedList::~LinkedList()
{
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