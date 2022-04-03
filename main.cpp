#include <iostream>
#include "ListOfNumbers.hpp"
using namespace std;

// Main function
int main()
{
	Node *a,*b,*c;
    ListOfNumbers * aList;
 	a = new Node(10);
 	b = new Node(5);
 	c = new Node(24);

 	cout << "Test the Sort Method: " << endl;

	a->SetNext(b);
	b->SetNext(c);

	cout << "Values: " << endl;
	a->PrintItem();
	b->PrintItem();
	c->PrintItem();

	// a is set as the head of List a
	aList = new ListOfNumbers(a);
	cout << "List a: " << endl;
	aList -> PrintList();

	cout << "Test the Add Method: " << endl;
	aList->Add(new Node(45));
	aList->Add(new Node(4));
	aList->Add(new Node(80));
	aList->Add(new Node(245));
	aList -> PrintList();

	cout << "Test the find Method: Find 80" << endl;
	Node* found = aList->Find(80);
	if (found != NULL) 
    {
		cout << "Node Found: " ;
		found->PrintItem();
	}
	else
    {
		cout << "Node not found: " << endl;
    }

	cout << "Test the findR Method: Find 80" << endl;
	Node* foundR = aList->FindR(80);
	if (foundR != NULL) 
    {
		cout << "Node Found: ";
		foundR->PrintItem();
	}
	else
    {
		cout << "Node not found: " << endl;
    }

	cout << "Test the AddR Method " << endl;
	aList -> AddR(new Node(1));
	aList -> AddR(new Node(688));
	aList -> PrintList();
	
	cout << "Test the Remove Method: Remove an Existing Number " << endl;
	aList -> Remove(2);
	aList -> PrintList();

	cout << "Test the Remove Method: Remove a Number Not Existing  " << endl;
	aList -> Remove(3);
	aList -> PrintList();

	cout << "Test the RemoveR Method: Remove an existing Number " << endl;
	aList -> Remove(455);
	aList -> PrintList();


	cout << "Test the Sort Method: " << endl;
	aList -> SortList();

	cout << "Sorted List: " << endl;
	aList -> PrintList();
}

// Gets a number
int GetNumber()
{
    int temp;
    cout << "Please enter a number\n"; // User inputs a umber (temp)
    cin >> temp;
    return temp;
};
