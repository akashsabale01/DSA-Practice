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

    void pushAtBack(int data);
    void display();
    void InsertInSortedLL(int data);
};

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

void LinkedList::InsertInSortedLL(int data)
{
    Node *t = new Node(data);

    // Check if Linked list is empty or not
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        Node *p = head;
        Node *q = NULL;
        while (p != NULL && (p->data < data))
        {
            q = p;
            p = p->next;
        }
        // check if it is 1st node
        if (p == head)
        {
            t->next = p;
            head = t;
        }
        // otherwise it it other node than 1st node
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    LinkedList list;

    list.pushAtBack(11);
    list.pushAtBack(22);
    list.pushAtBack(33);
    list.pushAtBack(44);
    list.pushAtBack(55);

    list.InsertInSortedLL(45);
    list.display();

    return 0;
}