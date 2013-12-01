/*
  Name: linkedList.cpp
  Copyright: 
  Author:  Alex Ryner
  Date: 12/01/13 22:49
  Description: implementation of functions for a linked list
*/
#include "linkedList_structNode.h"    // header file

using namespace std;

List::List():size(0),head(NULL) //initializer or initialization segment
{
}

List::List(const List& aList): size(aList.size)
{
  if (aList.head == NULL){
    head = NULL;  // original list is empty
    size = 0;
  }
  else
  {  // copy first node
    head = new ListNode;
    head->item = aList.head->item;

    // copy rest of list
    ListNode *newPtr = head;  // new list pointer
    // newPtr points to last node in new list
    // origPtr points to nodes in original list
    for (ListNode *origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next)
    {  
       newPtr->next = new ListNode;
       newPtr = newPtr->next;
       newPtr->item = origPtr->item;
    }  // end for

       newPtr->next = NULL;
  }  // end if
}  // end copy constructor

List::~List()
{
  //while (!isEmpty())
  //  remove(1);
  ListNode *curr=head;

  while (curr!=NULL){
    head = curr->next;
    delete curr; 
    curr = head;
  }
      
}  // end destructor

bool List::isEmpty() const
{
  return size == 0;
}  // end isEmpty

int List::getLength() const
{
  return size;
}  // end getLength

List::ListNode *List::find(const ListItemType& dataItem) const
{
	ListNode * curr = head;

	while(curr != NULL && curr->item != dataItem)
		curr = curr->next;

	return curr;
}  // end find

bool List::retrieve(ListItemType& dataItem) const 
{
	return find(dataItem) != NULL;
}  // end retrieve

void List::insert(const ListItemType& newItem)
{
      try
      {
        ListNode *newPtr = new ListNode;
        newPtr->item = newItem;
	ListNode *prev = head;

         // attach new node to list
	if(prev == NULL){
		head = newPtr;
		head->next = NULL;
	}
	else{
		if(prev->item > newPtr->item){
			newPtr->next = head;
			head = newPtr;
		}
		else {
			while((prev->next != NULL) && (prev->next->item < newPtr->item))
				prev = prev->next;

			newPtr->next = prev->next;
			prev->next = newPtr;
		}
	}
	
      }  // end try
      catch (bad_alloc e)
      {
        throw ListException("ListException: memory allocation failed on insert");
      }  // end catch
	
	size++;
}  // end insert

void List::remove(const ListItemType& newItem) 
{
	ListNode *cur = head;

	if(cur->item == newItem){
		head = head->next;
		delete cur;
	}

	else{
		while(cur->next != NULL){
			if(cur->next->item == newItem){
				ListNode *temp = cur->next;
				cur->next = temp->next;
				delete temp;
				break;
			}
			cur = cur->next;
		}
	}
}  // end remove

/*
void List::reverse()
{
	int index = size/2;
	ListNode *left = find(index);
	ListNode *right;

	if(size%2 == 0)
		right = find(index+1);
	else
		right = find(index+2);
	
	while(index > 0) {
		swap(left, right);
		index--;
		right = right->next;
		left = find(index);
	}
}
*/

void List::swap(ListNode * first, ListNode * second)
{
	ListItemType temp = first->item;
	first->item = second->item;
	second->item = temp;
}

void List::operator=(const List & rhs)
{
	while(size > 0) {
		remove(1);
	}

	if(rhs.head == NULL)
		head = NULL;

	else {
		ListNode *currO = rhs.head->next;
		head = new ListNode;
		head->item = rhs.head->item;
		ListNode *curr = head;

		while(currO != NULL) {
			curr->next = new ListNode;
			curr = curr->next;
			curr->item = currO->item;
			currO = currO->next;
		}
	}

	size = rhs.size;
}

ostream& operator<<(ostream& outputStream, const List& out)
{
	outputStream << "{";
	List::ListNode *curr = out.head;
	
	while(curr != NULL){
		outputStream << curr->item;
		curr = curr->next;

		if(curr != NULL)
			outputStream << ",";
	}
	
	outputStream << "}";

	return outputStream;
}


