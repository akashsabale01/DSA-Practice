#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    // we can make this variables private and make LinkedList as friend class of Node class
    // friend class LinkedList;
};

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void pushAtFront(int data);
    void pushAtBack(int data);
    void insert(int position, int data);
    void display();
    bool search(int key);
};

void LinkedList::pushAtFront(int data)
{
    // Empty linked list
    if (head == NULL)
    {
        // create new node  by using constructor Node() in Node class
        Node *temp = new Node(data);
        head = tail = temp;
    }
    // linked list is already created
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    // Note- here temp is local variable, So it will be destroyed after function ends
}

void LinkedList::pushAtBack(int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}

void LinkedList::insert(int position, int data)
{
    if (position < 0) // invalid position
        return;

    if (position == 0)
        pushAtFront(data);
    else
    {
        Node *correctPosition = head;

        for (int jump = 0; jump < position - 1 && correctPosition != NULL; jump++)
            correctPosition = correctPosition->next;

        // Now we are at correct Position, So add node
        Node *tempNode = new Node(data);
        tempNode->next = correctPosition->next;
        correctPosition->next = tempNode;
    }
}

void LinkedList::display()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool LinkedList::search(int key)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }

    return false;
}

int main()
{
    LinkedList list;

    list.pushAtBack(33);
    list.pushAtBack(44);
    list.pushAtBack(55);

    // list.pushAtFront(22);
    // list.pushAtFront(11);

    // list.insert(3, 40);

    // int k = 44;
    // if (list.search(k))
    //     cout << k << " found" << endl;
    // else
    //     cout << k << " Not found" << endl;
    
    
    
    
    list.display();

    return 0;
}