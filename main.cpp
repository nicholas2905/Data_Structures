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
 	
    	cout << "List a : " << endl;
 	a->PrintList();
 	
    	cout << "List c : " << endl;
 	c->PrintList();
	
	cout << "Test the Add Method : " << endl;
	a->Add(100);
	a->PrintList();

	cout << "Test the AddR Method " << endl;
	a->AddR(new ListOfNumbers(200));
	a->PrintList();
}
