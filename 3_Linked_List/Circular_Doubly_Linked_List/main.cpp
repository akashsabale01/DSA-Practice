#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class CircularDoublyLinkedList
{
private:
    Node *head;
public:
    CircularDoublyLinkedList(int A[], int n);
    void Display();
    int Length();
    void Insert(int position, int dt);
    int Delete(int position);

};

CircularDoublyLinkedList::CircularDoublyLinkedList(int A[], int n)
{
    Node *last,*t;
    // first node
    head = new Node;
    head->data = A[0];
    head->prev = head;
    head->next = head;

    last = head;

    // other node
    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
        head->prev = last;
    }
}

void CircularDoublyLinkedList::Display()
{
    Node *p = head;
    do
    {
        cout<<p->data<<" ";
        p = p->next;
    }while(p!=head);

    cout<<endl;
}

int CircularDoublyLinkedList::Length()
{
    Node *p = head;
    int len = 0;
    if(p==NULL)
        return len;
    do
    {
        len++;
        p = p->next;
    }while(p!=head);

    return len;
}

void CircularDoublyLinkedList::Insert(int position, int dt)
{
    if(position<0 || position>Length())
        return;

    Node *p=head;
    Node *t;

    // insert before first node
    if(position == 0)
    {
        t = new Node;
        t->data = dt;

        // Empty Circular doubly LL
        if(head == NULL)
        {
            t->next = t;
            t->prev = t;
            head = t;
        }
        // Nodes are present in Circular doubly LL
        else
        {
            t->next = head;
            t->prev = head->prev;
            head->prev->next = t;
            head->prev = t;
            head = t;
        }
    }
    else
    {
        for(int i=0;i<position-1;i++)
            p = p->next;

        t = new Node;
        t->data = dt;
        t->next = p->next;
        t->prev = p;
        t->next->prev = t;
        p->next = t;
    }
}

int CircularDoublyLinkedList::Delete(int position)
{
    if(position<1 || position>Length())
        return -1;
    int x;

    // Delete 1st node
    if(position==1)
    {
        Node *p = head;

        //No Nodes
        if(p==NULL)
            return -1;

        //Single Node in present in Circular doubly LL
        if(p->next == head)
        {
            x = head->data;
            head = NULL;
            delete p;
            p = NULL;
            return x;
        }

        //More than One Node present in Circular doubly LL
        else
        {
            x = head->data;
            head->next->prev = head->prev;
            head->prev->next = head->next;
            head = head->next;
            delete p;
            p = NULL;
            return x;
        }
    }
    // Delete other than 1st node
    else
    {
        Node *p = head;
        for(int i=0;i<position-1;i++)
            p = p->next;
        x = p->data;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        p = NULL;
        return x;
    }

}


int main()
{
    int A[] = {2,3,4,5,7};
    int n = sizeof(A)/sizeof(A[0]);

    CircularDoublyLinkedList CDL(A,n);

    CDL.Display();

//    cout<<"Length = "<<CDL.Length();

//    CDL.Insert(0,12);

    cout<<"Deleted element = "<<CDL.Delete(4)<<endl;

    CDL.Display();

    return 0;
}
