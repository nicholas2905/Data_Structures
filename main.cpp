#include <iostream>
//#include "ListOfNumbers.h"
#include "ListOfNumbers2.h"
using namespace std;

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
 	
    cout << "List 1 : " << endl;
 	a->PrintList();
 	
    cout << "List 2 : " << endl;
 	c->PrintList();
    cout << "Would you like to add a number to the list? (1 = yes, 2 = no):\n";
    int decision;
    cin >> decision;
    if (decision == 1)
    {
            cout << "Adding Number: " << endl;
 	        void Add(int v);
    }
    else
    {
        return 0;   
    }
}
