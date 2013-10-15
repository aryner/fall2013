/*
  Name: list.cpp--implementing the member functions
  Copyright: 
  Author: 
  Date: 19/09/11 18:43
  Description: 
*/


#include "list.h"  // header file

List::List(): size(0)
{

}  // end default constructor

bool List::isEmpty() const
{
   return size == 0;
}  // end isEmpty

int List::getLength() const
{
   return size;
}  // end getLength

void List::insert(const ListItemType& newItem)
   throw(ListIndexOutOfRangeException, ListException)
{
   ListException listEx("ListException: List full on insert");

   if (size >= MAX_LIST)
      throw listEx;
      //ListException("ListException: List full on insert");
   int index;

   if (size == 0)
      index = 0;

   else {
      index = size-1;
      while(items[index] > newItem && index >= 0) {
         items[index+1] = items[index];
         index--; 
       }
       index++;
   }

   items[index] = newItem;
/*
   for (int pos = size; pos >= index; --pos)
      items[translate(pos+1)] = items[translate(pos)];
      // insert new item
   items[translate(index)] = newItem;
*/
   ++size;  // increase the size of the list by one

}  // end insert


void List::remove(const ListItemType& newItem) 
     throw(ListIndexOutOfRangeException)
{
   ListIndexOutOfRangeException outOfRange;

   int start = 0;
   int end = size-1;
   int mid;
   bool found = false;

   while(!found && start <= end) {
      mid = start + (end-start)/2;
      if (items[mid] == newItem)
         found = true;
      else if (items[mid] > newItem)
         end = mid-1;
      else
         start = mid+1;
   }

   if (found){
      for(int i=mid; i<size; i++)
         items[i] = items[i+1];
      size--;
   }  

   else
      cout << "Could not remove, item not found" << endl;
}  // end remove

void List::retrieve(int index, ListItemType& dataItem) const
     throw(ListIndexOutOfRangeException)
{
   bool success;
   ListIndexOutOfRangeException outOfRange;
   
   success = (index >= 1) && (index <= size);
   
   if (!success) throw outOfRange;
   
   if (success)
      dataItem = items[translate(index)];
}  // end retrieve

int List::translate(int index) const
{
    return index-1;
}

void List::print() const
{
   ListItemType item;

   for (int i=0; i<size; i++) {
      item = items[i];
      cout << "\t\t" << item << endl;
   }
}
