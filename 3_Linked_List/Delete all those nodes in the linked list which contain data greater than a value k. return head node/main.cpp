#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Method for creating new node
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertNodeAtTail(int data);
    void printLinkedList();
};

void LinkedList::insertNodeAtTail(int data)
{
    // Create the new Node.
    Node *newNode = new Node(data);

    // Assign to head
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // If head is not null then insert at Tail i.e. Last, Traverse till end of list
    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp = newNode;
};

void LinkedList::printLinkedList()
{
    Node *temp = head;

    cout << endl;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create list: 7->3->4->8->5->1

    LinkedList list;

    list.insertNodeAtTail(7);
    list.insertNodeAtTail(3);
    list.insertNodeAtTail(4);
    list.insertNodeAtTail(8);
    list.insertNodeAtTail(5);
    list.insertNodeAtTail(5);

    list.printLinkedList();

    return 0;
}

// Note
// https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/
// https://www.geeksforgeeks.org/delete-nodes-list-greater-x/
