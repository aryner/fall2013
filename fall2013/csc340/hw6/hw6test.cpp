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
	findKLarge();
//	sortin();
//	findLargest();
//	reverseString();
}

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

}

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

	cout << "The " << k << " largest integer is: " << kLargest(numz, k-1, 0, 9) << endl;	
	cout << "Enter c to continue or any other key to go back" << endl;
	cin >> choice;
	
	if (choice == 'c')
		findKLarge();
}

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
}

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
}
