/*
  Name: testList.cpp
  Copyright: 
  Author: 
  Date: 19/09/11 18:49
  Description: 
*/

#include <stdlib.h>
#include <iostream>
#include "list.h" // ADT list operations

using namespace std;

void mult(List, List);
void div(List, List);
void add(List, List);
void sub(List, List);
void pre(List, List);
void post(List, List);

int main()
{
	List aList, bList;
	ListItemType dataItem;

	try {
		for (int i=0; i<5; i++) {
			aList.insert(i,rand()%10);
			bList.insert(i,rand()%10);
		}

	}
	catch (ListIndexOutOfRangeException & e) {
		cerr << e.what();
	}

	bool play = true;
	char choice;
	cout << "**********Welcome to the Q2 test program!***********" << endl;
	while (play) {	
		cout << "Enter a key from the menu below or q to quit" << endl;
		cout << "*=multiply, /=divide, +=add, -=subtract, a=list++, b=++list, d=display" << endl;
		cin >> choice;

		switch(choice) {
			case '*':
				mult(aList, bList);
				break;
			case '/':
				div(aList, bList);
				break;
			case '+':
				add(aList, bList);
				break;
			case '-':
				sub(aList, bList);
				break;
			case 'a':
				post(aList, bList);
				break;
			case 'b':
				pre(aList, bList);
				break;
			case 'd':
				cout << "List a is: " << aList << endl;
				cout << "List b is: " << bList << endl;
				break;
			case 'q':
				play = false;
				break;
			default:
				cout << "Invalid key, try again" << endl;
				break;
		}

	}

	return 0;
}


void mult(List aList, List bList) {
	char choice;
	int num;	
	bool play = true;
	cout << "List a is: " << aList << endl;
	cout << "List b is: " << bList << endl;

	while (play) {
		cout << "Enter a to use list a or b to use list b" << endl;
		cin >> choice;
		while (choice != 'a' && choice != 'b') {
			cout << "Invalid choice, enter either a or b" << endl;
			cin >> choice;
		}
		cout << "Enter the integer you wish to multiply list " << choice << " by" << endl;
		cin >> num;

		if (choice == 'a') 
			cout << aList << " * " << num << " = " << aList*num << endl;

		else 
			cout << bList << " * " << num << " = " << bList*num << endl;

		cout << "Enter * to continue multiplying or any other key to go back to the menu" << endl;
		cin >> choice;

		if (choice != '*') 
			play = false;
		
	}	
}

void div(List aList, List bList) {
	char choice;
	int num;	
	bool play = true;
	cout << "List a is: " << aList << endl;
	cout << "List b is: " << bList << endl;

	while (play) {
		cout << "Enter a to use list a or b to use list b" << endl;
		cin >> choice;
		while (choice != 'a' && choice != 'b') {
			cout << "Invalid choice, enter either a or b" << endl;
			cin >> choice;
		}
		cout << "Enter the integer you wish to divide list " << choice << " by" << endl;
		cin >> num;

		if (choice == 'a') 
			cout << aList << " / " << num << " = " << aList/num << endl;

		else 
			cout << bList << " / " << num << " = " << bList/num << endl;

		cout << "Enter / to continue dividing or any other key to go back to the menu" << endl;
		cin >> choice;

		if (choice != '/') 
			play = false;
		
	}	
}


void add(List aList, List bList) {
	cout << aList << " + " << bList << " = " << aList+bList << endl;
}


void sub(List aList, List bList) {
	cout << aList << " - " << bList << " = " << aList-bList << endl;
}

void pre(List aList, List bLIst) {
	cout << "++" << aList << " * 2 = "; 
	cout << ++aList * 2 << endl;
	cout << " and the list is now " << aList << endl;
}

void post(List aList, List bList) {
	cout << bList;
	cout  << "++" << " * 2 = " << bList++ * 2 << endl;
	cout << " and the list is now " << bList << endl;
}
