#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class StackUsingLinkedList
{
private:
    Node *top;

public:
    StackUsingLinkedList();
    ~StackUsingLinkedList();
    void Display();
    void Push(int dt);
    int Pop();
    int Peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();
};

StackUsingLinkedList::StackUsingLinkedList()
{
    top = NULL;
}

StackUsingLinkedList::~StackUsingLinkedList()
{
    Node *p = top;
    while(top!=NULL)
    {
        top = top->next;
        delete p;
        p = top;
    }

}


void StackUsingLinkedList::Display()
{
    Node *p = top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void StackUsingLinkedList::Push(int dt)
{
    Node *t = new Node;

    //check whether there is space or not for insertion
    // stack is full when we heap is full i.e. memory for t is not allocated
    // i.e. no node is created when stack is full
    if(t==NULL)
        cout<<"Stack is Full"<<endl;
    else
    {
        t->data = dt;
        t->next = top;
        top = t;
    }
}

int StackUsingLinkedList::Pop()
{
    int x = -1;
    //check whether stack is empty or not
    if(top==NULL)
        cout<<"Stack is Empty"<<endl;
    else
    {
        Node *t = top;
        x = t->data;
        top = top->next;
        delete t;
    }
    return x;
}

int StackUsingLinkedList::Peek(int index)
{
    int x = -1;
    if (isEmpty() == 1)
    {
        return x;
    }
    else
    {
        Node *p = top;
        for(int i=0;p!=NULL&&i<index-1;i++)
            p = p->next;
        if(p!=NULL)
            x = p->data;
        return x;
    }
}

int StackUsingLinkedList::isEmpty()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}

int StackUsingLinkedList::isFull()
{
    Node *t = new Node;
    int x = -1;
    if(t == NULL)
        x = 1;
    else
        x = 0;
    delete t;
    return x;
}

int StackUsingLinkedList::stackTop()
{
    if(top!=NULL)
        return top->data;
    else
        return -1;
}


int main()
{
    StackUsingLinkedList stk;

    int A[] = {11,22,33,44,55};
    int n = sizeof(A)/sizeof(A[0]);

    for(int i=0;i<n;i++)
        stk.Push(A[i]);

//    stk.Push(2);
//    stk.Push(3);

//    cout << "Stack peek at 3rd: " << stk.Peek(3) << endl;
//    cout << "Stack peek at 10th: " << stk.Peek(10) << endl;

    // Pop out elements from stack
    cout << "Popped: ";
    for (int i=0; i<n; i++){
        cout << stk.Pop() << ", ";
    }

    cout << endl;

    // Underflow
    cout << stk.Pop() << endl;


    cout<<"is Empty = "<<stk.isEmpty()<<endl;

    cout<<"is Full = "<<stk.isFull()<<endl;

    stk.Display();



//    cout<<stk.Pop()<<endl;
//    cout<<stk.Pop()<<endl;

//    cout<<stk.Peek(1)<<endl;
//    cout<<stk.Peek(3)<<endl;
//    cout<<stk.Peek(7)<<endl;

//    cout<<stk.stackTop()<<endl;

//    cout<<"is Empty = "<<stk.isEmpty()<<endl;
//
//    cout<<"is Full = "<<stk.isFull()<<endl;




//    stk.Display();

    return 0;
}
