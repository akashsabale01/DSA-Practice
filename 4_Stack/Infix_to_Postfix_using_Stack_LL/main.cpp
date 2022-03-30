#include <iostream>
#include <cstring>

using namespace std;

class Node
{
public:
    char data;
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
    void Push(char dt);
    char Pop();
    char Peek(int index);
    int isEmpty();
    int isFull();
    char stackTop();
//    Node* getTopPointer();
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

//Node* StackUsingLinkedList::getTopPointer()
//{
//    return top;
//}

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

void StackUsingLinkedList::Push(char dt)
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

char StackUsingLinkedList::Pop()
{
    char x = -1;
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

char StackUsingLinkedList::Peek(int index)
{
    char x = -1;
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

char StackUsingLinkedList::stackTop()
{
    if(top!=NULL)
        return top->data;
    else
        return -1;
}

int precedence(char x)
{
    if(x=='+'|| x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}

int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;

    return 1;
}

char* infixToPostfix(char infix[])
{
    StackUsingLinkedList stk;
    int i=0,j=0;

    char *postfix = new char[strlen(infix)+1];

    while(infix[i]!='\0')
    {
        // add to postfix string if it is operand
        if(isOperand(infix[i]))
        {
            postfix[j] = infix[i];
            j++,i++;
        }
        // else it is operator
        else
        {
            if(precedence(infix[i])>precedence(stk.stackTop()))
            {
                stk.Push(infix[i]);
                i++;
            }
            else
            {
                // precedence is lower or equal than operator present in stack's top
                // then pop out
                postfix[j] = stk.Pop();
                j++;
            }
        }
    }

    // Add element of stack to postfix expression if remaining
    while(!stk.isEmpty())
    {
        postfix[j] = stk.Pop();
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

string infixToPostfix(string infix)
{
    StackUsingLinkedList stk;

    string postfix;
    int i=0;
    int lenOfInfix = (int)infix.length();
    while(i != lenOfInfix)
    {
        // add to postfix string if it is operand
        if(isOperand(infix[i])== 1)
        {
            postfix += infix[i];
            i++;
        }
        // else it is operator
        else
        {
            if(stk.isEmpty() || ( precedence(infix[i]) > precedence(stk.stackTop()) ) )
            {
                // precedence is higher than operator present in stack's top
                // then push it in the stack and move i
                stk.Push(infix[i]);
                i++;
            }
            else
            {
                // precedence is lower or equal than operator present in stack's top
                // then pop out
                postfix += stk.Pop();
            }


        }
    }

    // Add element of stack to postfix expression if remaining
    while(!stk.isEmpty())
    {
        postfix += stk.Pop();
    }

    return postfix;
}

int main()
{
    char exp[] = "a+b*c-d/e";
    cout<<infixToPostfix(exp)<<endl;

    string exp1 = "a+b*c-d/e";
    cout<<infixToPostfix(exp1)<<endl;

    return 0;
}
