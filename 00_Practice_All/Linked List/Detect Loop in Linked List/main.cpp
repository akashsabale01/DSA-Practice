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
    bool isLoopPresent();
    Node *getHead() { return head; }
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

bool LinkedList::isLoopPresent()
{
    Node *p = head, *q = head;

    do
    {
        p = p->next; // increment 1 time
        q = q->next; // increment 2 times
        q = (q != NULL) ? q->next : NULL;
    } while (p != NULL && q != NULL && p != q);

    return p == q;
}

int main()
{
    LinkedList list;

    list.pushAtBack(11);
    list.pushAtBack(22);
    list.pushAtBack(33);
    list.pushAtBack(44);
    list.pushAtBack(55);

    // list.display();

    // Creating loop

    // Node *t1, *t2;
    // t1 = list.getHead();
    // t1 = t1->next->next; // t1 at 33
    // t2 = list.getHead();
    // t2 = t2->next->next->next->next; // t2 at 55

    // t2->next = t1;

    string haveLoop = (list.isLoopPresent() == true) ? "Yes" : "No";
    cout << haveLoop << endl;

    // list.display();

    return 0;
}