#include<iostream>
using namespace std;

class Node

{
	public:
	int data;
	//to children
	Node* left;
	Node* ryt;
	Node(value)
	{
		data=value;
		left=NULL;
		ryt=NULL;
	}

};


class bst
{
	public:
	Node* root; //papa
	bst()
	{
		root=NULL;
	}

	//data rules
	void instert(int value)
	{
		inserthelp(root,value);
	}
	void inserthelp(Node* curnt ,int value)
	{	
		//base casee if papa null
		if(root== NULL)
		{
			//new node
		
		
			root=new Node(value) ;
			return;
		
		}
		//celse compare with curr data
		
			//current value> data , move left
		else if(curnt->data > value)
		{	if(curnt->left==NULL)
			{
				curnt->left=new Node(value);
			}
			else
			inserthelp(curnt->left ,value);
		}
			//else move ryt insert
		else
		{	
			if(curnt->ryt==NULL)
			{
				curnt->ryt=new Node(value);
			}
			
			else
			inserthelp(curnt->ryt ,value);
		}


		
	}

}
void display()
	{displayHelper(root);}

  	void displayHelper(Node *curr)
	{
		// Base condition
		if (curr == NULL)
			return;
		// Display left.
		displayHelper(curr->left);
		// Display current
		cout << curr->data << ",";
		// Display right
		displayHelper(curr->right);
	}

	void displayFancy()
	{
		displayFancyHelper(root,0);
	}

	void displayFancyHelper(Node * cur,int s)
	{
		//when at the end of a trail return
		if(cur==NULL)
		{return;}
		//go left and increase the number of spaces
		displayFancyHelper(cur->left,s+1);
		//print the spaces
		for(int i=0;i<4*s;i++){cout<<" ";}
		//print the data
		cout<<cur->data<<endl;
		//go right and increase the number of spaces
		displayFancyHelper(cur->right,s+1);
  	}

	Node* search(Node * cur,int value)
	{
		if(cur==NULL)
		{return NULL;}
		else if(cur->data==value)
		{return cur;}
		else if(cur->data<value)
		{return search(cur->right,value);}
		else
		{return search(cur->left,value);}
	}
};

int main()
{


	bst t1;

	t1.insert(9);
	t1.insert(5);
	t1.insert(10);
	t1.insert(54);
	t1.insert(42);
	t1.insert(6);
	t1.insert(17);
	t1.insert(39);
	t1.display();
	cout<<endl<<endl;
	t1.displayFancy();
	if ( t1.search ( t1.root , 2) == NULL)
	{
		cout << "Not Found"<<endl;
	}
	else
	{
		cout<<"Found"<<endl;
	}

}
