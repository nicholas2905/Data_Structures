#include <iostream>
//#include "ListOfNumbers.h"
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

    // Requests a number
	int GetValue();
    ListOfNumbers* GetNext();

	// Prints a single item’s number
	void PrintItem();

	// Prints the whole list
	void PrintList();

	// Add Method
	void Add(ListOfNumbers *n);
	void Add(int v);

    // Recursive Add Method
	void AddR(ListOfNumbers *n);
	void AddR(int v);

	// Find Method	
	ListOfNumbers * Find(int number);

    //Recursive Find Method
	ListOfNumbers * FindR(int number);

	ListOfNumbers * Find_Smallest_Number();
	ListOfNumbers * Find_Largest_Number();

    // Deletes all items in the list
	ListOfNumbers* Delete_All_Items ();

    // Removes a single item in the list
	ListOfNumbers* Remove (int value);

	// Creates a new list of numbers
	void NewListOfNumbers();

};

ListOfNumbers::ListOfNumbers()
{
    number = 0;
    next = NULL;
};
ListOfNumbers::ListOfNumbers(int v)
{
    number = v;
    next = NULL;
};

void ListOfNumbers::SetValue(int v)
{
    number = v;
};
void ListOfNumbers::SetNext(ListOfNumbers *n)
{
    next = n;
};

// Prints a single item’s number
void ListOfNumbers::PrintItem()
{
    // The function displays the item, the current address, and the address of the next item
    cout << "Number = " << number << "      [Current Address: " << this << " ; Next Address: " << next << "]" << endl;
};

// Prints the whole list
void ListOfNumbers::PrintList()
{
    // Pointer current is pointing to the location of stored element
    ListOfNumbers *current = this;

    while (current != NULL) // The list can only be printed if there are items inside
    {
        current->PrintItem(); // PrintItem() will execute
        current = current->next;
    }
    if (current == NULL) // Case where list is empty
    {
        cout << "\nThere are no items in the list\n";
        return;
    }
};

// Add method (pointer)
void ListOfNumbers::Add(ListOfNumbers *n)
{
    ListOfNumbers *current = this;
    while (current->next != NULL)
    {
        current = current->next; // The pointer current will move on to the next
    }
    current->next = n;
};

// Adds a number to the list
void ListOfNumbers::Add(int v)
{
    ListOfNumbers *temp = new ListOfNumbers(v);

    Add(temp); // Add method (pointer)
};

// Adds a number to the list (recursive) (pointer)
void ListOfNumbers::AddR(ListOfNumbers *n)
{
    if (next == NULL)
    {
        next = n;
    }
    else
    {
        next->AddR(n);
    }
};

//Adds a number to the list (recursive)
void ListOfNumbers::AddR(int v)
{
    ListOfNumbers *temp = new ListOfNumbers(v);

    AddR(temp);
};

//Finds a number in the list
ListOfNumbers* ListOfNumbers::Find(int find_number)
{
    ListOfNumbers *current = this;
    if (find_number == number)
        {
            return current;
        }
    else
    {
        while (current -> next != NULL)
        {
            current = current -> next;
            if (find_number == current -> number)
            {
                return current;
            }
        }
        return NULL;
    }
};

//Finds a number in the list (recursive)
ListOfNumbers* ListOfNumbers::FindR(int find_number)
{
    if (find_number == number)
        {
            return this;
        }
    else
    {
        if (next != NULL)
        {
            return next -> FindR(find_number);
        }
        else
        {
            return NULL;
        };
    }  
};

// Deletes all the items in the list
ListOfNumbers* ListOfNumbers::Delete_All_Items()
{
    ListOfNumbers* temp;
    ListOfNumbers* NextCurrent;
    ListOfNumbers* current = this;
    NextCurrent = current->next;
    if (current != NULL)
    {
        while (temp!= NULL)
        {
            temp = temp->next;
        }
        current->next = NULL;
        NextCurrent = next;
        delete NextCurrent;
        current = NULL;
    }
};

//Deletes a number in the list
ListOfNumbers* ListOfNumbers::Remove (int delete_number)
{
    ListOfNumbers* temp;
    ListOfNumbers* tempNext;
    ListOfNumbers* previous;
    temp = FindR (delete_number);
    tempNext = temp->next;
    return temp;
};

// C;ass relating to sortlist
class Sortlist
{
private:
	ListOfNumbers *head;
public:
    Sortlist (ListOfNumbers* v)
    {
        head = v;
    }
	void sortList();
    void PrintList();
};

void Sortlist::sortList()
{
    // Current points to head
    ListOfNumbers* current = head, * index = NULL;
    int temp;

    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            // Node index will point to node next to current
            index = current->GetNext();

            while (index != NULL)
            {
                // The data will be swapped if (current node data) > (index node data)
                if (current->GetValue() > index->GetValue())
                {
                    temp = current->GetValue();
                    current->SetValue(index->GetValue()); 
                    index->SetValue(temp);
                }
                index = index->GetNext();
            }
            current = current->GetNext();
        }
    }
}
// Displays all the nodes present in the list
void Sortlist::PrintList()
{
    // Current will point to head
    ListOfNumbers* current = head;
    if (head == NULL) // Case where there is nothing in the list
    {
        cout << "The list is empty\n";
        return;
    }
    while (current != NULL) // Case where the list is not empty
    {
        cout << "Number = " << current->GetValue() << endl;
        current = current->GetNext();
    }
    cout << endl;
}
