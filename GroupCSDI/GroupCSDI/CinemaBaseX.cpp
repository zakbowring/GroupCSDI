#include "stdafx.h"
#include "CinemaBaseX.h"
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
	//Runs main program.

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
	return false;

}