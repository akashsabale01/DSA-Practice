#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;
public:
    DoublyLinkedList(int A[], int n);
//    Node* getHead()
//    {
//        return head;
//    }
    void Display();
    int Length();
    void Insert(int position, int dt);
    int Delete(int position);
    void Reverse();
};

DoublyLinkedList::DoublyLinkedList(int A[], int n)
{

    //create 1st node
    head = new Node;
    head->prev = NULL;
    head->data = A[0];
    head->next = NULL;

    // last points to head initially
    Node *last = head;
    Node *t;

    for(int i=1;i<n;i++)
    {
        // Create New node and change links of last node
        t = new Node;
        t->prev = last;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void DoublyLinkedList::Display()
{
    Node *p = head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int DoublyLinkedList::Length()
{
    Node *p = head;
    int len = 0;
    while(p!=NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void DoublyLinkedList::Insert(int position, int dt)
{
    Node *p = head;
    Node *t;
    if(position<0 || position>Length())
        return;

    // insert before 1st node
    if(position==0)
    {
        t = new Node;
        t->data = dt;
        t->prev = NULL;
        t->next = head;
        if(head!=NULL)
            head->prev = t;
        head = t;
    }
    // other than 0th position
    else
    {
        for(int i=0;i<position-1;i++)
        {
            p = p->next;
        }

        t = new Node;
        t->data = dt;
        t->next = p->next;
        t->prev = p;
        if(p->next != NULL)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int DoublyLinkedList::Delete(int position)
{
    Node *p = head;
    if(position<1 || position>Length())
        return -1;
    int x;
    // Delete 1st node
    if(position == 1)
    {
        head = head->next;
        // check whether next node i.e. head is Null or not
        if(head != NULL)
            head->prev = NULL;

        x = p->data;
        delete p;
    }
    // Delete other than 1st node
    else
    {
        for(int i=0;i<position-1;i++)
            p = p->next;

        p->prev->next = p->next;
        // Check whether p->next is null or not
        if(p->next != NULL)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

void DoublyLinkedList::Reverse()
{
    Node *p = head;
    Node *temp;
    while(p!=NULL)
    {
        // Swap p->prev and p->next with each other
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev; // move p to next node
        //check whether it is last node
        if(p!=NULL && p->next==NULL)
            head = p;
    }
}



int main()
{
    int A[] = {2,3,4,5,7};
    int n = sizeof(A)/sizeof(A[0]);

    DoublyLinkedList DL(A,n);

//    Node *headOfDL = DL.getHead();

    DL.Display();

//    cout<<"Length = "<<DL.Length()<<endl;

//    DL.Insert(0,10);

//    cout<<"Deleted element is "<<DL.Delete(8)<<endl;

    DL.Reverse();

    DL.Display();



    return 0;
}
