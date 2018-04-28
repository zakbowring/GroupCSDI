#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>


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

Node* LinkedList::InsertNode(int index, string x[21])
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
	for (int i = 0; i < 21; i++)
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

int LinkedList::FindNode(string x[21]) {
	Node* currNode = head;
	int currIndex = 1;
	while (currNode&&currNode->data != x) {
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode) return currIndex;
	return 0;
}

int LinkedList::StartUp() 
{
	LinkedList List;
	ifstream inFile; //opens an fstream for file reading
	inFile.open("testing.txt"); //opens up the specified file
	int count; //Count used for putting values into the array
	string temp[21]; //The array used to store and place data in linked list 
	int no1 = 0; //Used to insert nodes in linked list (order they're read out of file)

	if (inFile.is_open()) //If the file opens
	{
		count = 0;
			while (getline(inFile, temp[count], ','))
			{
				count++;
				getline(inFile, temp[count], ','); //Project Title [1]
				count++;
				getline(inFile, temp[count], ','); //Summary [2]
				count++;
				getline(inFile, temp[count], ','); //Genre [3]
				count++;
				getline(inFile, temp[count], ','); //Release Date [4]
				count++;
				getline(inFile, temp[count], ','); //Filiming Location [5]
				count++;
				getline(inFile, temp[count], ','); //Language[6]
				count++;
				getline(inFile, temp[count], ','); //Runtime [7]
				count++;
				getline(inFile, temp[count], ','); //Keywords[8]
				count++;
				getline(inFile, temp[count], ','); //Weekly ticket sales [9]
				count++;
				getline(inFile, temp[count], ','); //Project stage [10]
				count++;
				getline(inFile, temp[count], ','); //Crew [11]
				count++;
				getline(inFile, temp[count], ','); //Type of Disc [12]
				count++;
				getline(inFile, temp[count], ','); //Title [13]
				count++;
				getline(inFile, temp[count], ','); //Format [14]
				count++;
				getline(inFile, temp[count], ','); //Audio Format [15]
				count++;
				getline(inFile, temp[count], ','); //Bonus Features [16]
				count++;
				getline(inFile, temp[count], ','); //Disc Language(s) [17]
				count++;
				getline(inFile, temp[count], ','); //Retail Price [18]
				count++;
				getline(inFile, temp[count], ','); //Subtitle Langueage(s) [19]
				count++;
				getline(inFile, temp[count], ','); //Frame Aspect [20]
				List.InsertNode(no1, temp); //Inserts the array into the linked list
				cout << "-------------------------" << endl;
				List.DisplayList();
				cout << "-------------------------" << endl;
				no1++; //Increases so the next array is placed at the next spot in the linked list
				count = 0; //Resets for writing the next array
			}
		inFile.close();
	}
	else if (!inFile.is_open())
		cout << "There was an error in opening the data file!" << endl;
	string input;
	cin >> input;

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
		for (int i = 0; i < 21; i++)
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
	node *head = NULL;
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