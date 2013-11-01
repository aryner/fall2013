/*

	Name: hw6.cpp -- implementing the functions in hw6.h
	Author: Alex Ryner
	Date: 10/31/13
	Description: Implementation of the functions in hw6.h

*/

#include "hw6.h"
#include <string>
#include <stdlib.h>

using namespace::std;

//returns the reverse of the argumented string
string stringMirror(string word) {
	if(word.length() <= 1)
		return word;
	else {
		string sub = word.substr(1,word.length()-1);
		return stringMirror(sub) + word[0];
	}
} //end of stringMirro

//returns the largest int of the the int array numz
int largest(int* numz, int high, int curr, int last) {
	if(curr == last-1){
		return (numz[curr]>numz[high])?numz[curr]:numz[high];
	}
	else {
		return (numz[curr]>numz[high])?largest(numz, curr, curr+1, last):largest(numz, high, curr+1, last);
	}
}//end largest

//returns the kth largest int of the int array numz
int kLargest(int* numz, int k, int start, int end) 
{
	if(start == end)
		return numz[end];

	int index = rand()%(end-start) + start;
	int partition = numz[index];
	int front = start;
	int back = end;

	while(front<=back){
		while(numz[front]>partition)
			front++;
		while(numz[back]<partition)
			back--;

		if(front<=back){
			swap(numz,front,back);
			front++;
			back--;
		}
	}

	if(back == k) 
		return partition;
	
	else
		return (k>back) ? kLargest(numz, k, front, end) : kLargest(numz, k, start, back);
}//end of kLargest


//sorts the int array numz using the quick sort algorithm
void quickSort(int* numz, int start, int end)
{
	int index = (end-start)/2 + start;
	int partition = numz[index];
	int front = start;
	int back = end;

	while(front <= back) {
		while(numz[front]>partition)
			front++;
		while(numz[back]<partition)
			back--;

		if(front <= back){
			swap(numz, front, back);
			front++;
			back--;
		}
	}

	if(front<end)
		quickSort(numz, front, end);

	if(back>start)
		quickSort(numz, start, back);
}//end of quicksort

//displays the array numz
void displayArray(int* numz, int start, int end)
{
	cout << "[";
	
	for(int i=start; i<end-1; i++) 
		cout << numz[i] << ",";
	
	cout << numz[end-1] << "]" << endl;
}//end displayArray


//swaps two elements of the int array numz
void swap(int* numz, int one, int two) 
{
	int temp = numz[one];
	numz[one] = numz[two];
	numz[two] = temp;
}//end of swap
