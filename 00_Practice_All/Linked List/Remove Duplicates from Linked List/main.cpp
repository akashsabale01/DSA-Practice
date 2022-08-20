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
    void removeDuplicates();
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

// Sorted Array required
void LinkedList::removeDuplicates()
{
    Node *p = head, *q = head->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
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
    list.pushAtBack(44);
    list.pushAtBack(55);

    list.display();

    list.removeDuplicates();

    list.display();

    return 0;
}