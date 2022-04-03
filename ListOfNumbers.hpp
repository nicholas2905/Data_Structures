#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node * next;
    Node();

    Node(int v);

        void SetValue(int v);
        void SetNext(Node * n);

    int getValue();
    Node* getNext();

    // Prints a single item's number
    void PrintItem();

};
class ListOfNumbers 
{
private:
    Node * head;
public:
    // Prints the whole list
	void PrintList();

	ListOfNumbers();
    ListOfNumbers(Node * n);

    // Add Method
	void Add(Node * n);
	void Add(int n);

    // Recursive Add Method
	void AddR(Node * n);
	void AddR(int n);

    // Find Method	
	Node * Find(int value);

    // Recursive Find Method
	Node * FindR(int value);
    
    // Deletes all items in the list
    void RemoveAll();

    // Removes a single item in the list
	ListOfNumbers * Remove (int value);

	void SetValue(int v);

	void SetNext(ListOfNumbers *n);

    // Requests a number
	int GetValue();
    ListOfNumbers * GetNext();

	// Prints a single item’s number
	void PrintItem();

    // Sorting Method
    void SortList();
    void Swap(Node * n1, Node * n2);   

};

Node::Node()
{
    data = 0;
    next = NULL;
};
Node::Node(int v)
{
    data = v;
    next = NULL;
};

void Node::SetValue(int v)
{
    data = v;
};
void Node::SetNext(Node *n)
{
    next = n;
};

int Node::getValue()
{
    return data;
};
Node * Node::getNext()
{
    return next;
};

// Prints a single item’s number
void Node::PrintItem()
{
    // The function displays the item, the current address, and the address of the next item
    cout << "Number = " << data << "      [Current Address: " << this << " ; Next Address: " << next << "]" << endl;
};

// Prints the whole list
void ListOfNumbers::PrintList()
{
    // Pointer current is pointing to the location of stored element
    Node * current = this -> head;

    while (current != NULL) // The list can only be printed if there are items inside
    {
        current -> PrintItem(); // PrintItem() will execute
        current = current -> next;
    }
};

ListOfNumbers::ListOfNumbers()
{
    head = new Node();
};

ListOfNumbers::ListOfNumbers(Node * n)
{
    head = n;
};

// Add method (pointer)
void ListOfNumbers::Add(Node * n)
{
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        Node * current = this -> head;
        while (current -> next != NULL)
        {
            current = current -> next; // The pointer current will move on to the next
        }
    }
};

// Adds a number to the list
void ListOfNumbers::Add(int v)
{
    Node * temp = new Node(v);
    Add(temp); // Add method (pointer)
};

// Adds a number to the list (recursive) (pointer)
void ListOfNumbers::AddR(Node * n)
{
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        if (head -> next == NULL)
        {
            head -> next = n;
        }
        else
        {
            ListOfNumbers * current = new ListOfNumbers(head -> next);
            current -> AddR(n);
        }
    }
};

// Adds a number to the list (recursive)
void ListOfNumbers::AddR(int n)
{
    AddR(new Node(n));
};

// Finds a number in the list
Node * ListOfNumbers::Find(int find_number)
{
    Node * current = this -> head;
    if (find_number == head -> data)
        {
            return current;
        }
    else
    {
        while (current -> next != NULL)
        {
            current = current -> next;
            if (find_number == current -> data)
            {
                return current;
            }
        }
        return NULL;
    }
};

// inds a number in the list (recursive)
Node * ListOfNumbers::FindR(int find_number)
{
    if (find_number == head -> data)
        {
            return this -> head;
        }
    else
    {
        if (head -> next != NULL)
        {
            ListOfNumbers * current = new ListOfNumbers(head -> next);
            return current -> FindR(find_number);
        }
        else
        {
            return NULL;
        };
    }  
};  

//Deletes all the items in the list
void ListOfNumbers::RemoveAll()
{
    Node* current = this->head;   
    if (current != NULL)
    {
            head = current -> next; 
            delete current;           
            this->RemoveAll();
    }
   
};

//Deletes a number in the list
ListOfNumbers*  ListOfNumbers::Remove(int remValue) {
   
    Node* prev = this -> head; 
    Node* current = this -> head -> next; 

    if (this == NULL) 
    {
        return NULL;
    }
    else if (prev -> data == remValue) 
    {
        head = current;
        delete prev;        
    }
    else {

        while (current != NULL) 
        {
            if (current->data == remValue) 
            { 
                prev -> next = current -> next;
                delete current;
                break;
            }
            else 
            {
                prev = current;
                current = current -> next;
            }
        }
        if (current == NULL) {
            //A: The element is not found and not deleted. Informative message is printed
            cout << "Can't remove value: no match found.\n";
        }
    }
};

void ListOfNumbers::SortList() 
{
    // Node current will point to head  
    int swapp = 1;
    Node* current;
    Node* index = NULL;

    //Empty List
    if (head == NULL) 
    {
        return;
    }
    else 
    {
        do 
        {                       
            swapp = 0;
            current = head;
            while (current->next != index) {
                //If current node's data is greater than index's node data, swap the data between them  
                if (current->data > current->next->data) 
                {
                    Swap(current, current->next);
                    swapp = 1;
                }
                current = current->next;
            }
            index = current;
        } while (swapp);
    }
}
void ListOfNumbers::Swap(Node* n1, Node* n2) {
    Node* prevNode1 = NULL, * prevNode2 = NULL, * node1 = head, * node2 = head, * temp = NULL;

    //Checks if list is empty  
    if (head == NULL) 
    {
        return;
    }

    //If n1 and n2 are equal, then list will remain the same  
    if (n1->data == n2->data)
    {
        return;
    }
    // Search for node1  
    while (node1 != NULL && node1->data != n1->data) 
    {
        prevNode1 = node1;
        node1 = node1->next;
    }

    // Search for node2  
    while (node2 != NULL && node2->data != n2->data) 
    {
        prevNode2 = node2;
        node2 = node2->next;
    }

    if (node1 != NULL && node2 != NULL) 
    {

        // If previous node to node1 is not null then, it will point to node2  
        if (prevNode1 != NULL)
        {
            prevNode1->next = node2;
        }
        else
        {
            head = node2;
        }
        // If previous node to node2 is not null then, it will point to node1  
        if (prevNode2 != NULL)
        {
            prevNode2->next = node1;
        }
        else
        {
            head = node1;
        }
        // Swaps the next nodes of node1 and node2  
        temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
    }
    else 
    {
        cout << "Swapping is not possible\n";
    }
}
