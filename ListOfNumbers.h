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
	void AddRPointer(ListOfNumbers *n);
	void AddR(int v);

	// Requests a number
	int GetNumber();

	// Finds a object	
	ListOfNumbers * Find(int number);
	ListOfNumbers * FindR(int number);

	// Creates a new list of numbers
	void NewListOfNumbers();

	// Deletes a number in the list
	ListOfNumbers* Delete_Number (int deleting_number);
};
