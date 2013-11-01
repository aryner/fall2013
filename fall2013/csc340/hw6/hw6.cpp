#include "hw6.h"
#include <string>
#include <stdlib.h>

using namespace::std;


string stringMirror(string word) {
	if(word.length() <= 1)
		return word;
	else {
		string sub = word.substr(1,word.length()-1);
		return stringMirror(sub) + word[0];
	}
}

int largest(int* numz, int high, int curr, int last) {
	if(curr == last-1){
		return (numz[curr]>numz[high])?numz[curr]:numz[high];
	}
	else {
		return (numz[curr]>numz[high])?largest(numz, curr, curr+1, last):largest(numz, high, curr+1, last);
	}
}

int kLargest(int* numz, int k, int start, int end) 
{
	if(start == end)
		return numz[end];

	int index = rand()%(end-start) + start;
	int partition = numz[index];
	int front = start;
	int back = end;

	displayArray(numz,start,end+1);
	
	cout << "partition = " << partition << " front = " << front << " back = " << back << " index = " << index << " k = " << k << endl;

	while(front<=back){
		while(numz[front]>=partition)
			front++;
		while(numz[back]<partition)
			back--;

		if(front<=back){
			swap(numz,front,back);
			front++;
			back--;
		}
	}

	displayArray(numz, start, end+1);

	cout << " back = " << back << " front = " << front << endl;

	if(back == k) 
		return partition;
	
	else
		return (k>back) ? kLargest(numz, k, front, end) : kLargest(numz, k, start, back);
}

void quickSort(int* numz, int start, int end)
{
	int index = (end-start)/2 + start;
	int partition = numz[index];
	int front = start;
	int back = end;

	while(front < back) {
		while(numz[front]>partition)
			front++;
		while(numz[back]<partition)
			back--;

		if(front < back){
			swap(numz, front, back);
			front++;
			back--;
		}
	}

	if(front<end)
		quickSort(numz, front, end);

	if(back>start)
		quickSort(numz, start, back);
}

void displayArray(int* numz, int start, int end)
{
	cout << "[";
	
	for(int i=start; i<end-1; i++) 
		cout << numz[i] << ",";
	
	cout << numz[end-1] << "]" << endl;
}

void swap(int* numz, int one, int two) 
{
	int temp = numz[one];
	numz[one] = numz[two];
	numz[two] = temp;
}
