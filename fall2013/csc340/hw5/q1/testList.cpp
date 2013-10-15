/*
  Name: testList.cpp
  Copyright: 
  Author: Alex Ryner
  Date: 10/14/13
  Description: Test program for a sorted list
*/

#include <stdlib.h>
#include <iostream>
#include "list.h" // ADT list operations

using namespace std;

void insert(List &);
void remove(List &);

int main()
{
	//list to be used in the test
	List aList;

	try{
		//initial loading of the list
		for(int i=0; i<5; i++) {
			aList.insert(rand()%10);
		}
	}
	catch (ListIndexOutOfRangeException & e){
		cerr << e.what();
	}

	cout << "***Welcome to the Q1 test program!***" << endl;
	cout << "\tThe starting list is: " << endl;

	aList.print();

	bool play = true;
	char choice;

	while(play) {
		cout << "Enter a key from the menu below or q to quit" << endl;
		cout << "********i=insert, r=remove, d=display*******" << endl;
		cin >> choice;

		switch(choice) {
			case 'i':
				insert(aList);
				break;
			case 'r':
				remove(aList);
				break;
			case 'd':
				aList.print();
				break;
			case 'q':
				play = false;
				break;
			default:
				cout << "invalid choice, try again" << endl;
				break;
		}
	}


	return 0;

}

//function to test the insert function
void insert(List &list) {
	char choice = 'i';
	int num;

	while(choice == 'i') {
		cout << "Enter an integer to be added to the list." <<endl;
		cin >> num;
		
		try{
			list.insert(num);
		}
		catch (ListIndexOutOfRangeException & e){
			cerr << e.what();
		}
		catch (...) {}

		cout << "After inserting, the list is:" << endl;
		list.print();
		
		cout << "Enter i to insert again or any other key to go back to the menu" << endl;
		cin >> choice;
	
	}
}

//function to test the remove function 
void remove(List &list) {
	char choice = 'r';
	int num;

	while(choice == 'r') {
		cout << "Enter an integer from the list to be removed" << endl;
		cin >> num;

		try {
			list.remove(num);
		}
		catch (...) {}

		cout << "After removing, the list is: " << endl;
		list.print();

		cout << "Enter r to remove again or any other key to go back to the menu" << endl;
		cin >> choice;
	}
}

