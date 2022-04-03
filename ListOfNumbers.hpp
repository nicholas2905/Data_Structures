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
	void Remove (int value);

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
    // Case where the list is empty
    if (head == NULL)
    {
        head = n; // Adding a node to the head
    }
    else
    {
        Node * current = this -> head;
        // Until you did not reach the end of the list
        while (current -> next != NULL)
        {
            current = current -> next; // The pointer current will move on to the next
        }
        current = n;
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
    // Case where the list is empty
    if (head == NULL)
    {
        head = n; // The node will be added to the head
    }
    else
    {
        // If the next node is empty
        if (head -> next == NULL)
        {
            head -> next = n; // The node will be added
        }
        // If the next node is not empty
        else
        {
            // You go ahead until you reach the end of the list
            ListOfNumbers * current = new ListOfNumbers(head -> next);
            current -> AddR(n);
        }
    }
};

// Adds a number to the list (recursive)
void ListOfNumbers::AddR(int n)
{
    Node * temp = new Node(n);
    AddR(temp);
};

// Finds a number in the list
Node * ListOfNumbers::Find(int find_number)
{
    Node * current = this -> head;
    // Case where the head is the number you want to find
    if (find_number == head -> data)
        {
            return current;
        }
    else
    {
        // Until you reach the end of the list
        while (current -> next != NULL)
        {
            current = current -> next; // Current moves to next
            // If current is the number you want to find
            if (find_number == current -> data)
            {
                return current;
            }
        }
        // You did not find the number
        return NULL;
    }
};

// Finds a number in the list (recursive)
Node * ListOfNumbers::FindR(int find_number)
{
    // Case where the head is the number you want to find
    if (find_number == head -> data)
        {
            return this -> head; // Returns the value
        }
    else
    {
        // If you did not reach the end of the list
        if (head -> next != NULL)
        {
            // Creates a new list of numbers starting from the next node
            ListOfNumbers * current = new ListOfNumbers(head -> next);
            return current -> FindR(find_number);
        }
        // If you reached the end of the list without finding the number
        else
        {
            return NULL;
        };
    }  
};  

// Deletes all the items in the list
void ListOfNumbers::RemoveAll()
{
    Node * current = head;

    // Case where the list is not empty   
    if (current != NULL)
    {
        // Deletes the first element in the list
        head = current -> next; 
        delete current; // Deletes the head from the memory          
        this -> RemoveAll();
    }  
};

// Deletes a number in the list
void ListOfNumbers::Remove(int remValue) 
{
    // Previous is set as the head
    Node * prev = this -> head;

    // Current is set as the next
    Node * current = this -> head -> next; 

    // Case where the list is not empty
    if (head != NULL) 
    {
    //Case where the head is the node to delete     
    if (prev -> data == remValue) 
    {
        head = current; // Deletes from the list
        delete prev; // Deletes the requested node from memory
    }
    else 
    {
        while (current != NULL) 
        {
            if (current -> data == remValue) 
            { 
                // Deletes from list
                prev -> next = current -> next; // Changes pointer to node after deleted one
                delete current; // Deletes the requested node from memory
                break;
            }
            else 
            {
                prev = current; // Moves previous to the current node
                current = current -> next; // Moves current to the next node
            }
        }
        if (current == NULL) 
        {
            // The element is not found and not deleted. Informative message is printed
            cout << "Can't remove the value: no match found.\n";
        }
    }
    }
    else
    {
        // Case where the list is empty
        cout << "Can't remove the value: the list is empty.\n";
    }   
};

void ListOfNumbers::SortList() 
{
    // Used to exit the while loop
    int swap_variable;

    Node * current;

    // Refers to the tail of the list
    Node * index = NULL;

    // Case where the list is empty
    if (head == NULL) 
    {
        return;
    }
    else 
    {
        do 
        {                       
            
            swap_variable = 0; // Used for the loop to work
            current = head; // Current is set to the start of the list
            while (current -> next != index) 
            {
                // If current node's data is greater than index's node data, swap the data between them  
                if (current -> data > current -> next -> data) 
                {
                    Swap(current, current -> next);
                    swap_variable = 1; // If the first swap goes, it repeats because list is not ordered
                }
                current = current->next; // Current moves forward
            }
            index = current; // Index moves back
        } while (swap_variable == 1); // While swap_variable = 1 (boolean)
    }
}
void ListOfNumbers::Swap(Node* a, Node* b) 
{
    Node * PrevA = NULL, * PrevB = NULL, * node1 = head, * node2 = head, * temp = NULL;

    // Case where the list is empty  
    if (head == NULL) 
    {
        return;
    }

    // Case where the nodes are equal  
    if (a -> data == b -> data)
    {
        return; // List stays the same
    }

    // Search for 'a'
    // While the list is not empty and the data in the node is not what you are looking for  
    while (node1 != NULL && node1 -> data != a -> data) 
    {
        PrevA = node1; // Previous becomes the node before the current
        node1 = node1 -> next; // Current moves on to the next
    }

    // Search for 'b'
    // While the list is not empty and the data in the node is not what you are looking for  
    while (node2 != NULL && node2 -> data != b -> data) 
    {
        PrevB = node2; // Previous becomes the node before the current
        node2 = node2 -> next; // Current moves on to the next
    }

    // Case where both nodes are not empty
    if (node1 != NULL && node2 != NULL) 
    {
        // If node1 is not the start of the list
        if (PrevA != NULL)
        {
            PrevA -> next = node2; // Previous will point to node2 now instead of node1 because of the swap
        }

        // If node1 is the start of the list
        else
        {
            head = node2; // Then after the swap node2 will become the new start of the list
        }

        // If node2 is not the start of the list  
        if (PrevB != NULL)
        {
            PrevB -> next = node1; // Previous will point to node1 now instead of node2 because of the swap
        }

        // If node2 is the start of the list
        else
        {
            head = node1; // Then after the swap node1 will become the new start of the list
        }

        // Swaps the next nodes of node1 and node2  
        temp = node1 -> next; // Temp points to the node after node1
        node1 -> next = node2 -> next; // The one after node1 becomes what used to be after node2
        node2 -> next = temp; // node2 inherits temp
    }
    // If both nodes are empty
    else 
    {
        cout << "Swapping is not possible\n";
    }
}
