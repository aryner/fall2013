/*

	name: hw6.h--consisting of the interface of hw6
	Author: Alex Ryner
	Date: 10/31/13
	Description: header file for hw6

*/


#include <iostream>
#include <string>

using namespace::std;

//returns the reverse of the argumented string
string stringMirror(string word);

//returns the largest int in the array numz
int largest(int* numz, int high, int curr, int last);

//returns the kth largest int in the array numz
int kLargest(int* numz, int k, int start, int end);

//switches 2 elements in the int array numz
void swap(int*numz, int one, int two);

//uses the quicksort algorithim to sort the array numz
void quickSort(int* numz, int start, int end);

//prints the array
void displayArray(int* numz, int start, int end);
