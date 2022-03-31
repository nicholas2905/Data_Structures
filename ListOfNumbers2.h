#include <iostream>
#include "ListOfNumbers.h"
using namespace std;


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
    cout << "Number = " << number << "      [" << this << " ; " << next << "]" << endl;
};
// Prints the whole list
void ListOfNumbers::PrintList()
{
    ListOfNumbers *current = this;

    while (current != NULL)
    {
        cout << current->number << "      [" << current << "]" << endl;
        current = current->next;
    }
};
std::ostream & operator << (std::ostream &out, const ListOfNumbers &a)
{
    out << "List of Numbers Value = " << a.number;
    return out;
};

//Adds a number to the list (pointer)
void ListOfNumbers::Add(ListOfNumbers *n)
{
    ListOfNumbers *current = this;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->SetNext(n);
};

//Adds a number to the list
void ListOfNumbers::Add(int v)
{
    ListOfNumbers *temp = new ListOfNumbers(v);

    Add(temp);
};

//Adds a number to the list (recursive) (pointer)
void ListOfNumbers::AddRPointer(ListOfNumbers *n)
{
    if (next == NULL)
    {
        next = n;
    }
    else
    {
        next->AddRPointer(n);
    }
};

//Adds a number to the list (recursive)
void ListOfNumbers::AddR(int v)
{
    ListOfNumbers *temp = new ListOfNumbers(v);

    AddRPointer(temp);
};

//Gets a number
int ListOfNumbers::GetNumber()
{
    int temp;
    cout << "Please enter a number:\n";
    cin >> temp;
    return temp;
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

//Finds the smallest number in the list
ListOfNumbers * ListOfNumbers::Find_Smallest_Number()
{
    ListOfNumbers* current = this->next;
    ListOfNumbers* min = this;
    while(current != NULL)
        if (current->number <= min -> number)
        {
            min = current;
        }
        current = current->next;
    return min;
};

//Finds the largest number in the list
ListOfNumbers * ListOfNumbers::Find_Largest_Number()
{
    ListOfNumbers* current = this->next;
    ListOfNumbers* max = this;
    while(current != NULL)
        if (current->number >= max -> number)
        {
            max = current;
        }
        current = current->next;
    return max;
};

//Creates a new list of numbers
void ListOfNumbers::NewListOfNumbers()
{
    int temp;
    temp = GetNumber(); //Void getnumber is used so that the user inputs a number
    AddR(temp);
};

//Deletes all the items in the list
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
ListOfNumbers* ListOfNumbers::Delete_Number (int delete_number)
{
    ListOfNumbers* temp;
    ListOfNumbers* tempNext;
    ListOfNumbers* previous;
    temp = FindR (delete_number);
    tempNext = temp->next;
};
