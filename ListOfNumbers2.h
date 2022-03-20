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
void ListOfNumbers::Add(ListOfNumbers *n)
{
    ListOfNumbers *current = this;
    while (current != NULL)
    {
        current = current->next;
    }
    current->SetNext(n);
};

void ListOfNumbers::Add(int v)
{
    ListOfNumbers *temp = new ListOfNumbers(v);

    Add(temp);
};
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
void ListOfNumbers::AddR(int v)
{
    ListOfNumbers *temp = new ListOfNumbers(v);

    AddRPointer(temp);
};
int ListOfNumbers::GetNumber()
{
    int temp;
    cout << "Please enter a number:\n";
    cin >> temp;
    return temp;
};
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
void ListOfNumbers::NewListOfNumbers()
{
    int temp;
    temp = GetNumber();
    AddR(temp);
};
ListOfNumbers* ListOfNumbers::Delete_Number (int delete_number)
{


};
