#include <iostream>
#include "ListOfNumbers.h"
using namespace std;


ListOfNumbers::ListOfNumbers()
{
    number = 0;
    next = NULL;
}
ListOfNumbers::ListOfNumbers(int v)
{
    number = v;
    next = NULL;
}

void ListOfNumbers::SetValue(int v)
{
    number = v;
}
void ListOfNumbers::SetNext(ListOfNumbers *n)
{
    next = n;
}
// Prints a single item’s number
void ListOfNumbers::PrintItem()
{
    cout << "Number = " << number << "      [" << this << " ; " << next << "]" << endl;
}
// Prints the whole list
void ListOfNumbers::PrintList()
{
    ListOfNumbers *current = this;

    while (current != NULL)
    {
        cout << current->number << "      [" << current << "]" << endl;
        current = current->next;
    }
}
std::ostream & operator << (std::ostream &out, const ListOfNumbers &a)
{
    out << "List of Numbers Value = " << a.number;
    return out;
}
void ListOfNumbers::Add(ListOfNumbers *n)
{
    ListOfNumbers *current = this;
    while (current != NULL)
    {
        current = current->next;
    }
    current->SetNext(n);
}

void ListOfNumbers::Add(int v)
{
    ListOfNumbers *temp = new ListOfNumbers(v);

    Add(temp);
}
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
}
void ListOfNumbers::AddR(int v)
{
    ListOfNumbers *temp = new ListOfNumbers(v);

    AddR(temp);
}
void ListOfNumbers::GetNumber()
{
    int inputted_number;
    cout << "Please enter a number:\n";
    cin >> number;
    SetValue(inputted_number);
}
void ListOfNumbers::Find(ListOfNumbers *n)
{
    ListOfNumbers *current = this;
    while (current->next == this) 
        cout << current;
        //current = current->next;
    //current->next = (n);
};
