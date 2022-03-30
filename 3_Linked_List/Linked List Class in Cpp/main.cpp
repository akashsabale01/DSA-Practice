#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    LinkedList(int A[], int n);
    ~LinkedList();

    Node* getHead()
    {
        return head;
    }

    void Display();
    int Length();
    int LengthR(Node *p);
    void Insert(int position, int dt);
    int Delete(int position);
    void RDisplay1(Node *p);
//    void DisplayRec1(Node *p);
//    int Add();
//    int AddR();



};

LinkedList::LinkedList(int A[], int n)
{
    // Creating 1st node
    head = new Node;
    head->data = A[0];
    head->next = NULL;

    //  we create a last Node which help us to
    Node *temp, *last;
    last = head;

    // Creating remaining nodes
    for(int i=1;i<n;i++)
    {
        // Create a temporary Node
        temp = new Node;

        // Fill temporary Node
        temp->data = A[i];
        temp->next = NULL;

        // last's next is pointing to temp
        last->next = temp;
        last = temp;
    }
}

LinkedList::~LinkedList()
{
    Node *p = head;
    while(head!=NULL)
    {
        head = head->next;
        delete p;
        p = head;
    }
}

void LinkedList::Display()
{
    Node *p = head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void LinkedList::RDisplay1(Node *p)
{
    // Head Recursion - print at calling phase
    // print in same order
    if(p!=NULL)
    {
        cout<< p->data <<" ";
        //passing next node pointer
        RDisplay1(p->next);
    }
}

int LinkedList::Length()
{
    Node *p = head;
    int cnt=0;
    while(p!=NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

int LinkedList::LengthR(Node *p)
{
    if(p==NULL)
        return 0;
    else
    {
//        return CountR(p->next)+1;
        return 1+LengthR(p->next);
    }
}

void LinkedList::Insert(int position, int dt)
{
    Node *p = head;
    if(position<0 || position>Length())
        return;

    // position is valid
    Node *t = new Node;
    t->data = dt;

    // Insert in Front
    if(position == 0)
    {
        t->next = head;
        head = t;
    }
    // Insert in other position than Front like 1,2,3 or last
    else if(position>0)
    {
        // move pointer p to that position
        for(int i=0;(i<position-1&&p);i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int position)
{
    Node *p = head;
    Node *q = NULL;
    int x = -1;

    if(position<1 || position>Length())
        return -1;

    // case 1 - delete 1st node
    if(position == 1)
    {
        x = p->data;
        head = head->next;
        delete p;
        return x;
    }

    // case 2 - delete other than 1st node
    else
    {
        for(int i=0;i<position-1;i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

//void LinkedList::DisplayRec1(Node *p)
//{
//    Node *q = head;
//
//    if(p==NULL)
//        return;
//
//    if(p->next!=q )
//    {
//        cout<<p->data<<" ";
//        DisplayRec1(p->next);
//    }
//}
//


int main()
{
    int A[] = {5,6,2,14,8};
    int n = sizeof(A)/sizeof(A[0]);

    LinkedList L(A,n);
    Node *LLHead = L.getHead();

//    L.Insert(0,10);
//    L.Delete(4);
//    L.Display();
    L.RDisplay1(LLHead);
//    L.DisplayRec1(LLHead);
    cout<<endl;

//    cout<<L.LengthR(LLHead)<<endl;

    return 0;
}
