#include <iostream>
using namespace std;

class ListOfNumbers 
{
private:
	int number;
	ListOfNumbers *next;
public:
	ListOfNumbers();
	ListOfNumbers(int v);

	void SetValue(int v);
	void SetNext(ListOfNumbers *n);

	// Prints a single item’s number
	void PrintItem();

	// Prints the whole list
	void PrintList();		
};
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
};