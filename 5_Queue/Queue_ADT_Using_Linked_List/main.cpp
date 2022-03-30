#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
} ;

class QueueUsingLinkedList
{
private:
    Node* Front;
    Node* Rear;

public:
    QueueUsingLinkedList();
    ~QueueUsingLinkedList();
    void enqueue(int x);
    int dequeue();
    int isFull();
    int isEmpty();
    void display();

};

QueueUsingLinkedList::QueueUsingLinkedList()
{
    Front = NULL;
    Rear = NULL;
}

QueueUsingLinkedList::~QueueUsingLinkedList()
{
    Node *p = Front;
    while(Front!=NULL)
    {
        Front = Front->next;
        delete p;
        p = Front;
    }
}

int QueueUsingLinkedList::isFull()
{
    Node *t = new Node;
    // when heap will became full then queue becomes full
    // because in LL we not give size it grows as per the input
    if(t == NULL)
    {
        // t will be not created if heap is full
        return 1;
    }
    return 0;
}

int QueueUsingLinkedList::isEmpty()
{
    if(Front == NULL)
        return 1;

    return 0;
}

void QueueUsingLinkedList::enqueue(int x)
{
    if(isFull() == 1)
        cout<<"Queue is Full"<<endl;
    else
    {
        Node *t = new Node;
        t->data = x;
        t->next = NULL;
        // Check whether are we creating 1st node
        if(Front == NULL)
        {
            Front = t;
            Rear = t;
        }
        else
        {
            Rear->next = t;
            Rear = t;
        }
    }
}

int QueueUsingLinkedList::dequeue()
{
    int x = -1;
    if(isEmpty() == 1)
        cout<<"Queue is Empty"<<endl;
    else
    {
        Node *p = Front;
        x = p->data;
        Front = Front->next;
        delete p;
    }
    return x;
}


void QueueUsingLinkedList::display()
{
    if(isEmpty() == 1)
        return;

    cout<<"Queue = ";
    Node *p = Front;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}


int main()
{
    QueueUsingLinkedList q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.display();

    cout<<"Deleted Element = "<<q.dequeue()<<endl;
    cout<<"Deleted Element = "<<q.dequeue()<<endl;

    cout<<"is Empty = "<<q.isEmpty()<<endl;
    cout<<"is Full = "<<q.isFull()<<endl;


    q.display();


    return 0;
}
