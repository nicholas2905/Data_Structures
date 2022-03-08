#include <iostream>
//using namespace std;

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

	// Overload the operator <<
	friend std::ostream &operator << (std::ostream &out, const ListOfNumbers &a);

	// Adds a new item to the list
	void Add(ListOfNumbers *n);
	void Add(int v);
	void AddR(ListOfNumbers *n);
	void AddR(int v);

	// Finds a object	
	void Find(int v);
	void FindR(int v);	
	
};
//ListOfNumbers::ListOfNumbers()
//{
	//next = NULL;
//}
//void ListOfNumbers::AddList()
//{
//	next = NULL;
////	ListOfNumbers *n = this;
	//while (n->next != NULL)
	//	n = n->next;
//};

