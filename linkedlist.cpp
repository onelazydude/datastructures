#include<iostream>
using namespace std;

/*

This is a basic implementation of a linked list. I chose c++ because of familiarity.
If you happen to read this, thank you.
1--->2--->3--->4--->5--->NULL

     temp--->

*/


struct Node
{
	int data;
	Node* link;
};

Node* head;

void Reverse()
{
 // this is daunting !!
 
 Node* current = head; // pointing to the current node
 Node* prev = NULL; // for keeping track of the previous node
 Node* next; // Keeping track of the next node
 /*
  With these tools at out disposal, we can easily reverse a linked list.
  1. make current point to the head, 
  2. make next point to the next element to the head
  3. make prev point to null
  4. Loop through till current  is the last element. i.e current != NULL
  5. In each step, make "next", the next of current, make current point to the previous, again update previous to current,then current to the "next"
  
  prv-->current-->next
 */
 
  while(current != NULL)
  {
  	next = current->link;
  	current->link = prev;
  	prev = current;
  	current = next;
  }
  head = prev; // finally assign head to prev when done looping through.
}

void RecReverse(Node* node)
{
	
	//1--->2--->3--->4--->5--->NULL
	if(node->link == NULL)
	{
		head = node;
		return;
	}
	RecReverse(node->link);
	node->link->link = node;
	node->link = NULL;
	
}
void insertHead(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->link = head;
	head = temp;
}

int findHeight()
{
	int height = 0;
	Node* temp = head;
	while(temp != NULL)
	{
		height++;
		temp = temp->link;
	}
        return height;
}
void insertAt(int data, int pos)
{
	Node* temp = new Node();
	temp->data = data;
	if(head == NULL)
	{
		cout<<"The list is empty"<<endl;
		return;
	}
	if(pos == 1)
	{
		temp->link = head;
		head = temp;
		return;
	}
	Node* temp1 = head;
	for(int i = 1;i<pos-1;i++)
	{
		if(temp1->link == NULL)
			return; // this is required if the desired position exceeds the limit of the linked list. 
			        // we can add a new element on the length+1(th) position, anything beyond that is unreachable
		temp1 = temp1->link;
	}
	temp->link = temp1->link;
	temp1->link = temp;
}

void deleteAtHead()
{
	Node* temp = head;
	head = head->link;
	delete temp;
}
void deleteAt(int pos)
{
	
	
	if(pos == 1)
	{
		deleteAtHead();
		return;
	}
	
	if(head == NULL)
		return;
	Node* temp = head;
	for(int i = 1;i<pos-1;i++)
	{
		temp = temp->link;
		if(temp->link == NULL)
			return; // checking again if the next pointer is pointing to NULL, this happens if the position exceeds the limit of the linked list.
	}
	Node* temp1 = temp->link;
	temp->link = temp->link->link;
	delete temp1;
	
	
}

void printLink()
{

	if(head == NULL)
	{
		cout<<"The list is empty"<<endl;
		return;
	}
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ---> ";
		temp = temp->link;
	}
	cout<<"NULL"<<endl;
}
void printReverseRec(Node* node)
{
	if(node == NULL) //try with node->link 
		return;
	printReverseRec(node->link);
	cout<<node->data;
}

void printRec(Node* node)
{
	if(node == NULL) return;
	cout<<node->data<<" ";
	printRec(node->link);
	//1--->2--->3--->4--->5--->NULL
}
int main()
{
	insertHead(5);
	insertHead(6);
	insertHead(8);
	insertHead(1);
	insertHead(2);
	
	printLink();
	printRec(head);
	cout<<endl;
	printReverseRec(head);
	cout<<endl;
}
