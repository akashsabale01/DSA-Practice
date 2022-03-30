#include <iostream>
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
    Node *first;
    Node *second;

public:
    void create1(int A[],int n1);
    void create2(int B[], int n2, Node *q);

    Node* getHeadOf1stLL()
    {
        return first;
    }

    void IntersectionPointofTwoLL();

};

void LinkedList::create1(int A[],int n1)
{
    first = new Node;
    first->data = A[0];
    first->next = NULL;

    Node *last1 = first;
    Node *t;

    for(int i=1;i<n1;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last1->next;
        last1->next = t;
        last1 = t;
    }
}

void LinkedList::create2(int B[], int n2, Node *q)
{
    second = new Node;
    second->data = B[0];
    second->next = NULL;

    Node *last2 = second;
    Node *t;

    for(int i=1;i<n2;i++)
    {
        t = new Node;
        t->data = B[i];
        t->next = last2->next;
        last2->next = t;
        last2 = t;
    }

    // Here q is address of node where we have connected second LL to first LL
    last2->next = q;
}

void LinkedList::IntersectionPointofTwoLL()
{
    Node *p = first;
    Node *q = second;

    // push Address of each node of 1st LL in stack 1
    stack<Node*> stk1;
    while(p!=NULL)
    {
        stk1.push(p);
        p = p->next;
    }

    // push Address of each node of 2nd LL in stack 2
    stack<Node*> stk2;
    while(q!=NULL)
    {
        stk2.push(q);
        q = q->next;
    }

    Node *r; // for storing intersecting point
    while(stk1.top() == stk2.top())
    {
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    cout<<"Intersecting Node = "<<r->data<<endl;
}

int main()
{
    // Create First Linked List
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int n1 = sizeof(A)/sizeof(A[0]);

    LinkedList LL;
    LL.create1(A,n1);

    // Create Second Linked List
    Node *temp = LL.getHeadOf1stLL();

    // move temp pointer to node where we have connected second LL to first LL
    int i = 3;
    while(i>0)
    {
        temp = temp->next;
        i--;
    }
    cout<<"Here We have Connected 2nd LL to 1st LL at node = "<<temp->data<<endl;

    int B[] = {2, 4, 6, 8, 10};
    int n2 = sizeof(B)/sizeof(B[0]);

    LL.create2(B,n2,temp);

    LL.IntersectionPointofTwoLL();

    return 0;
}
