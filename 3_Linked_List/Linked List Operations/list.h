#include <iostream>
using namespace std;

//Forward declaration for class List - here we use class List before its defination in Node class
class List;

//create Node
class Node
{
public:
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }

//    int getData()
//    {
//        return data;
//    }

//    friend class List;
};

// Create Linked list
class List
{
    Node *head;
    Node *tail;

public:

    List()
    {
        head = NULL;
        tail = NULL;
    }

//    Node* getHead()
//    {
//        return head;
//    }

    void Push_front(int data);
    void Push_back(int data);
    void Display();

};

void List::Push_front(int data)
{
    // Empty linked list
    if(head==NULL)
    {
        //create new node n by using constructor Node() in Node class
        Node *n = new Node(data);
        head = tail = n;
        return;
    }
    // linked list is already created
    else
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
    }
    //Note- here n is local variable, So it will be destroyed after function ends
}

 void List::Push_back(int data)
{
    if(head==NULL)
    {
        Node *n = new Node(data);
        head = tail = n;
        return;
    }
    else
    {
        Node *n = new Node(data);
        tail->next = n;
        tail = n;
    }
}

void List::Display()
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}







