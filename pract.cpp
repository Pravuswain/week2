#include<iostream>
using namespace std;

class node
{
	public:
//node contains val
	int val;
//next should contain a node
	node*next; 
//constructor
	node(int newval)
	{
//by default it contains value
		val = newval;
//next points to NULL
		next =NULL;	
	}
		
};

class linkedlist
{
	public:
//define head
	node * head;
//constructor
	linkedlist()
	{
		head = NULL;
	}
	void insert(int newval)
	{
//create a node with new val
		node*temp = new node(newval);
//if head is present
//point the next to the head
		temp ->next = head;
//transfer value of head to temp
		head = temp;

	}
	void display()
	{
//start from head
		node * curr = head;
//keep printing head till its NULL
		while (curr != NULL)
		{
			cout << curr->val<< "->";
//go to nest node
			curr = curr->next; 
		}

	}
	int count()
	{
//start from head
		node*curr = head;
//begin the count
		int count = 0;
//use loop count till curr is not null
		while(curr != NULL)
		{
			count ++;
			curr = curr -> next;

		}
		return count;

	}
	node* getpos(int pos)
	{
		int count = 1;
		node * curr = head;
		while (count < (pos - 1))
		{
			curr = curr -> next;
			count ++;
		}
		return curr;
	}

	void insertat(int pos, int newval)
	{
		
		if(pos<1 || (pos > (count()+1)))
		{
			
		}
//to check
		node * curr = getpos(pos - 1);
		if (pos == 1){
			insert(newval);
		}
		else{
//create a new node
			node * temp = new node(newval);
//point the temp next to the curr next
			temp -> next = curr -> next;
//poiint the curr next to temp next
			curr -> next = temp;
		}
	
	}
	void delet()
	{
//begin from head 
//name the head temp
		node*temp = head;
//transfer the value to next
		head = head-> next;
//delete temp
		delete temp;
	}

};
class stacks 
{
	public:
	node* top;
	linkedlist l1;
//constructor
	stacks()
	{
		
//top is same a as head
		top=l1.head; 
	}
//push function same as insert
	void push(int val)
	{
//use the insert function of linked list
		l1.insert(val);
//specify that head is now top
		top = l1.head;

	}
	int count()
	{
//return the count function of linkedlist
		return l1.count(); 
	}
	void pop()
	{
//use the delet function
//check stacks node
		if(top == NULL)
		{
			cout<<"nothing to pop"<<endl;		
		
			return ;		
		}
		l1.delet();
//mention the top
		top = l1.head;

	}

	void display()
	{
		l1.display();
		top= l1.head;

	}
};



int main()
{
//create a stacks
//push 5 items
//pop six items
//print stack after every push and pop
	stacks  s1;
	s1.push(1);
	s1.push(3);
	s1.push(2);
	s1.push(4);
	s1.push(5); 
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.display();	
}
