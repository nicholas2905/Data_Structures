#include <iostream>
#include "ListOfNumbers.hpp"
using namespace std;

// Main function
int main()
{
	ListOfNumbers *a,*b,*c;
 	a = new ListOfNumbers(10);
 	b = new ListOfNumbers(5);
 	c = new ListOfNumbers(-24);

 	a->SetNext(b);
 	b->SetNext(c);
 	
    cout << "Values : " << endl;
 	a->PrintItem();
 	b->PrintItem();
 	c->PrintItem();
 	
    cout << "List a : " << endl;
 	a->PrintList();
 	
    cout << "\nList c : " << endl;
 	c->PrintList();

    cout << "Add method (test) " << endl;
    a->Add(new ListOfNumbers(45));
    a->PrintList();

    cout << "AddR method (test) " << endl;
    a->AddR(new ListOfNumbers(3));
    a->PrintList();

    cout << "Sort method (test) " << endl;
    Sortlist* s = new Sortlist (a);
    s->sortList();

    // Displays the sorted list
    cout << "The Sorted List " << endl;
    s->PrintList();
}

// Gets a number
int GetNumber()
{
    int temp;
    cout << "Please enter a number\n"; // User inputs a umber (temp)
    cin >> temp;
    return temp;
}
