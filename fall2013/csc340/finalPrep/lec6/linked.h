#include <iostream>

using namespace::std;

struct node
{
	int data;
	node *next;
};


class linked
{
public:
	linked():head(NULL),size(0)
	{
	}

	void push(int item){
		try{
			node *newNode = new node;

			newNode->data = item;
			newNode->next = NULL;

			if(size==0){
				head = newNode;
			}

			else {
				node *back = getBack();
				back->next = newNode;
			}
		} catch(bad_alloc e){}
		size++;
	}

	node* getBack()
	{
		node *curr = head;
		int i=0;
		while(i<size-1){
			curr = curr->next;
			i++;
		}
		return curr;
	}

	friend ostream & operator<<(ostream & os, const linked & rhs)
	{
		os << "<";
		int i=0;
		node *curr = rhs.head;
		while(i<rhs.size){
			os << curr->data;
			curr = curr->next;
			if(i<rhs.size-1)
				os << ",";
			i++;
		}
		os << ">";

		return os;
	}


private:

	node *head;
	int size;
};
