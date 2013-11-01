/*
	Name: hw6test.cpp
	Author: Alex Ryner
	Date: 10/31/13
	Description: Test for the hw6 functions
*/

#include "hw6.h"
#include <iostream>
#include <string>

using namespace::std;

void findKLarge();
void reverseString();
void findLargest();
void sortin();

int main()
{
	char choice = 'c';

	cout << "***  Welcome to the hw6 test program   ***" << endl;

	while(choice != 'q'){
		cout << "Use the menu below to test a function" << endl;
		cout << "k = find kth largest, s = quicksort, l = find largest, r = reveseString, q = quit" << endl;
		cin >> choice;

		switch(choice){
			case 'k' :
				findKLarge();
				break;
			case 's' :
				sortin();
				break;
			case 'l' :
				findLargest();
				break;
			case 'r' :
				reverseString();
				break;
			case 'q' :
				break;
			default :
				cout << "Invalid option, try again" << endl;
		}
	}

	return 0;
}//end of main

//Test for the quick sort method
void sortin()
{

	int numz[10];
	char choice;

	cout << "Enter 10 integers to be sorted" << endl;

	for(int i=0;i<10;i++) {
		cin >> numz[i];
	}

	quickSort(numz, 0, 9);

	cout << "The sorted ints are : ";
	displayArray(numz,0,10);
	cout << "Enter c to continue or any other key to go back" << endl;
	cin >> choice;
	
	if (choice == 'c')
		sortin();

}//end of sortin

//test for kLargest
void findKLarge() 
{
	int numz[10];
	char choice;
	int k;

	cout << "Enter 10 integers" << endl;

	for(int i=0;i<10;i++) {
		cin >> numz[i];
	}

	cout << "Enter an integer k to find the kth largest integer" << endl;
	cin >> k;

	cout << "The " << k << " largest integer is: " << kLargest(numz, k-2, 0, 9) << endl;	
	cout << "Enter c to continue or any other key to go back" << endl;
	cin >> choice;
	
	if (choice == 'c')
		findKLarge();
}//end of findKLarge

//test for largest
void findLargest()
{
	int numz[10];
	char choice;

	cout << "Enter 10 integers to find the largest among the group" << endl;

	for(int i=0;i<10;i++) {
		cin >> numz[i];
	}

	cout << "The largest is: " << largest(numz, 0, 0, 10) << endl;
	cout << "Enter c to continue or any other key to go back" << endl;
	cin >> choice;
	
	if (choice == 'c')
		findLargest();
}//end of findLargest


//test for stringMirror
void reverseString() 
{
	string word;
	char choice;

	cout << "Enter a string to get to see it written backwards" << endl;
	cin >> word;

	cout << stringMirror(word) << endl;

	cout << "Enter c to do this again or any other key to go back" << endl;
	cin >> choice;

	if(choice == 'c')
		reverseString();		
}//end of reverseString
