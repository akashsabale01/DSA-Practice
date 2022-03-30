#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *head;

public:
    // Parameterized Constructor
    CircularLinkedList(int A[],int n);

    Node* getHead()
    {
        return head;
    }

    void Display();
    void DisplayRec(Node *p);
//    void DisplayRec1(Node *p);
    int Length(Node *p);
    void Insert(Node *p, int position, int dt);
    int Delete(Node *p, int position);

    ~CircularLinkedList();

};

CircularLinkedList::CircularLinkedList(int A[],int n)
{
    //create 1st node
    head = new Node;
    head->data = A[0];
    head->next = head;

    Node *t,*tail;
    tail = head;

    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

void CircularLinkedList::Display()
{
    Node *p = head;
    do
    {
        cout<<p->data<<" ";
        p = p->next;
    }while(p!=head);

    cout<<endl;
}

int CircularLinkedList::Length(Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    }while(p!=head);

    return len;
}

void CircularLinkedList::DisplayRec(Node *p)
{
    static int flag = 0;
    // terminate condition
    if(p!=head || flag==0)
    {
        flag = 1;
        cout<<p->data<<" ";
        DisplayRec(p->next);
    }
    flag = 0; // after 1st traversal of LL we assign flag to 0
}

void CircularLinkedList::Insert(Node *p, int index, int dt)
{
    if(index<0 || index>Length(p))
        return;

    Node *t;
    //Before 1st node
    if(index == 0)
    {
        t = new Node;
        t->data = dt;
        // check whether LL in empty or not
        if(head == NULL)
        {
            // LL is empty
            head = t;
            head->next = head;
        }
        else
        {
            // LL is not empty
            while(p->next!=head) // go to last node
            {
                p = p->next;
            }
            // we are at last node
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    //After 1st node
    else
    {
        //Move to that position
        for(int i=0;i<index-1;i++)
        {
            p= p->next;
        }
        // we are at that position
        t = new Node;
        t->data = dt;
        t->next = p->next;
        p->next = t;

    }
}

int CircularLinkedList::Delete(Node *p, int position)
{
    if(position<=0 || position>Length(p))
        return -1;

    int x;
    if(position == 1)
    {
        while(p->next!=head)
        {
            p = p->next;
        }
        x = head->data;
        // Check whether there are more than one node
        // only one node
        if(p==head)
        {
            delete head;
            head = NULL;
        }
        // more than one node
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    // position >0
    else
    {
        for(int i=0;i<position-2;i++)
        {
            p = p->next;
        }
        Node *q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
        q = NULL;
    }

    return x;
}






//void CircularLinkedList::DisplayRec1(Node *p)
//{
//    Node *q = head;
//    if(p->next==NULL)
//        cout<<"hello"<<" ";
//        return;
//    if(p->next!=q)
//    {
//        cout<<p->data<<" ";
//        DisplayRec1(p->next);
//    }
//}

CircularLinkedList::~CircularLinkedList()
{
    Node *temp = head; // store first value of head
    Node *t = NULL; // t pointer for deleting nodes

    do
    {
      t = head;
      head = head->next;
      delete t;
    }while(head!=temp);

    head = NULL; // make head as NULL after deleting all nodes
}


int main()
{
    int A[] = {3,5,6,8,9};
    int n = sizeof(A)/sizeof(A[0]);

    CircularLinkedList CL(A,n);

    Node *HeadOfCl = CL.getHead();

    CL.Display();

//    CL.DisplayRec(HeadOfCl);

//    CL.DisplayRec1(HeadOfCl); // this is not working

//    CL.Insert(HeadOfCl,0,10);

    cout<<"Deleted element is "<<CL.Delete(HeadOfCl,5)<<endl;

    CL.Display();


    return 0;
}
