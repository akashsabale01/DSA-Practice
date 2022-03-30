#include <iostream>
#include <cmath>
#include <stack>

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
    LinkedList(int A[],int n);
    void Display();
    int Length();
    void MiddleUsingLength();
    void MiddleUsingTwoPointers();
    void MiddleUsingStack();
};

LinkedList::LinkedList(int A[], int n)
{
    head = new Node;
    head->data = A[0];
    head->next = NULL;

    Node *last = head;
    Node *t;

    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void LinkedList::Display()
{
    Node *p = head;
    while(p!= NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int LinkedList::Length()
{
    Node *p = head;
    int len = 0;

    if(p == NULL)
        return len;

    while(p!= NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList::MiddleUsingLength()
{
    // ceil() means upper value i.e. ceil(4.2) = 5
    int length = Length();
    int midIndex = (int)ceil(length/2.0);

    Node *p = head;

    for(int i=0;i<midIndex-1;i++)
        p = p->next;

    cout<<"Middle using Length = "<<p->data<<endl;
}

void LinkedList::MiddleUsingTwoPointers()
{
    Node *p = head;
    Node *q = head;

    while(q!=NULL)
    {
        q = q->next;
        // check q for 2nd jump
        if(q != NULL)
            q = q->next;
        // Move p when q != NULL
        if(q!=NULL)
            p = p->next;
    }
    cout<<"Middle using Two pointers = "<<p->data<<endl;
}

void LinkedList::MiddleUsingStack()
{
    stack<Node*> stk;

    Node *p = head;

    // push address of each node at a time in stack
    while(p!=NULL)
    {
        stk.push(p);
        p = p->next;
    }

    int stkLength = stk.size();
    int popLength = (int)floor(stkLength/2.0);

    // pop values up to popLength
    while(popLength != 0)
    {
        stk.pop();
        popLength--;
    }
    cout<<"Middle using stack = "<< stk.top()->data <<endl;
}



int main()
{
    int A[] = {3,4,5,6,7,8};
    int n = sizeof(A)/sizeof(A[0]);

    LinkedList L(A,n);

    L.Display();

//    cout<<"Length = "<< L.Length() <<endl;

    L.MiddleUsingLength();

    L.MiddleUsingTwoPointers();

    L.MiddleUsingStack();


    return 0;
}
