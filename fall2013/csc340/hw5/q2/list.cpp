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

void List::insert(int index, const ListItemType& newItem)
   throw(ListIndexOutOfRangeException, ListException)
{
   ListException listEx("ListException: List full on insert");
   ListIndexOutOfRangeException outOfRange("ListIndexOutOfRangeException: Bad index on insert");                                    
   if (size >= MAX_LIST)
      throw listEx;
      //ListException("ListException: List full on insert");

   if (index >= 0 && index <= size)
   {
	int pos = size-1;
	while(pos > index) {
	   items[pos+1] = items[pos];
	   pos--;
	}
	items[index] = newItem;
	size++;
   }
   else  // index out of range
      throw outOfRange;
      //ListIndexOutOfRangeException( "ListIndexOutOfRangeException: Bad index on insert");
   // end if
}  // end insert


void List::remove(int index) 
     throw(ListIndexOutOfRangeException)
{
   bool success;
   ListIndexOutOfRangeException outOfRange;
   
   success = (index >= 1) && (index <= size);
   
   if (!success) throw outOfRange;
   
   if (success)
   {  // delete item by shifting all items at positions >
      // index toward the beginning of the list
      // (no shift if index == size)
      for (int fromPosition = index + 1;
	   fromPosition <= size;
	   ++fromPosition)
         items[translate(fromPosition - 1)] = items[translate(fromPosition)];
      --size;  // decrease the size of the list by one
   }  // end if

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

List List::operator+(List rightSide) const
{
   List result;
   ListItemType temp;

   for(int i=0; i<size; i++) {
      rightSide.retrieve(i+1,temp);
      temp += items[i];
      result.insert(i,temp);
   }

   return result;
}

List& List::operator++()
{
	for(int i=0; i<size; i++) {
		items[i] = items[i]++;
	}
	return *this;
}

List List::operator++(int blank) 
{
	List result = *this;
	for(int i=0; i<size; i++) {
		items[i] = items[i]++;
	}
	return result;
}

List List::operator-(List rightSide) const
{
   List result;
   ListItemType temp;

   for(int i=0; i<size; i++) {
      rightSide.retrieve(i+1,temp);
      temp = items[i]-temp;
      result.insert(i,temp);
   }

   return result;
}

List List::operator*(ListItemType rightSide) const
{
   List result;
   ListItemType temp;
   
   for(int i=0; i<size; i++) {
      temp = items[i] * rightSide;
      result.insert(i,temp);
   }

   return result;
}

List List::operator/(ListItemType rightSide) const
{
   List result;
   ListItemType temp;
   
   for(int i=0; i<size; i++) {
      temp = items[i] / rightSide;
      result.insert(i,temp);
   }

   return result;
}

ostream& operator<<(ostream& outputStream, const List& out)
{
   outputStream << "<";
   int leng = out.getLength();
   ListItemType data;
   for(int i=0; i<leng; i++){
      out.retrieve(i+1,data);
      outputStream << out.items[i];
      if (i<leng-1)
         outputStream << ",";
   }
   outputStream << ">" ;
   return outputStream;
}

int List::translate(int index) const
{
    return index-1;
}

