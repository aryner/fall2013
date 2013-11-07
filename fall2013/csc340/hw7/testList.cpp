/*
  Name: testList.cpp
  Copyright: 
  Author: Alex Ryner
  Date: 11/6/13
  Description: Progam to test a list using a dynamic array
*/

#include <stdlib.h>
#include <iostream>
#include "list.h" // ADT list operations

using namespace std;

int main()
{
	List aList(5);

	for(int i=0;i<5;i++)
		aList.insert(i,i);

	cout << "List A is is initially: " << aList << " with a max starting size of 5 elements" << endl;
	cout << "Now we will try inserting 95 more elements into list A to get: " << endl;

	for(int i=5;i<100;i++)
		aList.insert(i,i);

	cout << aList << endl;

	cout << "Now we will remove 90 elements:" << endl;

	for(int i=100;i>10;i--)
		aList.remove(i);

	cout << aList << endl;
	cout << "Now we will call List bList(aList) and display the contents of our new B list:" << endl;

	List bList(aList);

	cout << bList << endl;

	cout << "Now we will add 5 more elements to list B:" << endl;
	
	for(int i=10;i<15;i++)
		bList.insert(i,i);

	cout << bList << endl;

	cout << "Finally we wil set list A equal to list B and display the contents of list A: " << endl;

	aList = bList;

	cout << aList << endl;

	return 0;
}


