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
    void reverseLLUsingArray();
    void reverseLL(); // reverse Links
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

void LinkedList::reverseLLUsingArray()
{
    // find length of Linked list
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    // create temp array
    int *arr = new int[len];

    // copy elements from Linked list to array
    temp = head;
    int i = 0;
    while (temp != NULL)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    // copy elements from array to Linked list
    temp = head;
    int j = len - 1;
    while (temp != NULL)
    {
        temp->data = arr[j--];
        temp = temp->next;
    }

    // release memory
    delete[] arr;
    arr = NULL;
}

// Using 3 sliding pointers
void LinkedList::reverseLL()
{
    Node *p = head, *q = NULL, *r = NULL;

    while (p != NULL)
    {
        // sliding pointers
        r = q;
        q = p;
        p = p->next;
        // change link of q
        q->next = r;
    }
    head = q;
}

int main()
{
    LinkedList list;

    list.pushAtBack(11);
    list.pushAtBack(22);
    list.pushAtBack(33);
    list.pushAtBack(44);
    list.pushAtBack(55);

    list.display();

    // list.reverseLLUsingArray();
    list.reverseLL();

    list.display();

    return 0;
}