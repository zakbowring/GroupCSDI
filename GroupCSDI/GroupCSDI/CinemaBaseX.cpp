#include "stdafx.h"
#include "CinemaBaseX.h"
#include "LinkedList.h"
#include "MergeSort.h"
#include "Node.h"
#include "Project.h"
#include <string>
#include <iostream>
using namespace std;

//Contructor
CinemaBaseX::CinemaBaseX()
{
}

//Deconstructor 
CinemaBaseX::~CinemaBaseX()
{

}

bool CinemaBaseX::Run() {
	//Display Main Screen
	CinemaBaseX System;
	MergeSort sort;
	LinkedList List;
	Node firstNode;
	List.StartUp();
	firstNode = List.FindNode(["1"]);
	sort.Run(&firstNode);
	cout << "-------------Cinema Base X-------------" << endl;
	cout << "---------By Trek Star Pictures---------\n" << endl;
	cout << "To enter the program type 'enter', to close the program type 'exit'" << endl;
	string input;
	cin >> input;
	if (input == "enter")
		cout << "entered the program" << endl;
	else if (input == "exit")
		cout << "Exit the program" << endl;
	else
		cout << "Input invalid" << endl;
	cin >> input;
	System.Shutdown();
	return false;

}

void CinemaBaseX::Shutdown() {
	cout << "Shutting Down..." << endl;
	cout << "3" << endl;
	cout << "2" << endl;
	cout << "1" << endl;
}
