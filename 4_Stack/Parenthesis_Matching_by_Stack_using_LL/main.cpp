#include <iostream>
#include <cstring>
#include <map>

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


bool isBalanced(char exp[])
{
    StackUsingLinkedList stk;

    int n = strlen(exp);
    for(int i=0;i<n;i++)
    {
        if(exp[i] == '(')
        {
            stk.Push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            //Check whether stack is empty or not
            if(stk.isEmpty() == 1)
                return true;
            else
            {
                stk.Pop();
            }
        }
    }

    //Check whether stack is empty or not
    if(stk.isEmpty() == 1)
        return true; // stack is empty
    else
        return false; // stack is Not empty

}

//Method 1
//By if else
bool isBalancedExtendedMethod1(char exp[])
{
    StackUsingLinkedList stk;

    int n = strlen(exp);
    for(int i=0;i<n;i++)
    {
        if(exp[i] == '(' ||exp[i] == '{' ||exp[i] == '[')
        {
            stk.Push(exp[i]);
        }
        else if(exp[i] == ')'||exp[i] == '}' ||exp[i] == ']')
        {
            //Check whether stack is empty or not
            if(stk.isEmpty() == 1)
                return false;
            else
            {
                char x = stk.stackTop();
                char y = exp[i];
                if((x=='(' && y==')') || (x=='[' && y==']') || (x=='{' && y=='}'))
                    stk.Pop();
                else
                    return false;
            }
        }
    }

    //Check whether stack is empty or not
    if(stk.isEmpty() == 1)
        return true; // stack is empty
    else
        return false; // stack is Not empty

}


//Method 2
// Using ASCII values
//    ( = 40 ,   ) = 41
//    [ = 91 ,   ] = 93
//    { = 123,   } = 125
bool isBalancedExtendedMethod2(char exp[])
{
    StackUsingLinkedList stk;

    int n = strlen(exp);
    for(int i=0;i<n;i++)
    {
        if(exp[i] == '(' ||exp[i] == '{' ||exp[i] == '[')
        {
            stk.Push(exp[i]);
        }
        else if(exp[i] == ')'||exp[i] == '}' ||exp[i] == ']')
        {
            //Check whether stack is empty or not
            if(stk.isEmpty() == 1)
                return false;
            else
            {
                int a=0;
                // increment ASCII values of opening brackets
                if(exp[i]==')')
                    a = stk.stackTop() + 1;
                else if(exp[i]==']'|| exp[i]=='}')
                    a = stk.stackTop() + 2;

                // check whether both are same
                if(exp[i] == a)
                    stk.Pop();
                else
                    return false;
            }
        }
    }

    //Check whether stack is empty or not
    if(stk.isEmpty() == 1)
        return true; // stack is empty
    else
        return false; // stack is Not empty
}

// Method 3
// Using Map<char,char>
bool isBalancedExtendedMethod3(char exp[])
{
    //Create Map - key value pair
    map<char, char> mp;
    mp[')'] = '(';
    mp['}'] = '{';
    mp[']'] = '[';

// Create map iterator -- iterator is pointer to map
//  and used for iterating map which gives key,value pair as result
    map<char, char>::iterator itr;

    // create stack
    StackUsingLinkedList stk;

    int n = strlen(exp);

    for(int i=0;i<n;i++)
    {
        // push if it is opening bracket
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
            stk.Push(exp[i]);
        // pop if it is closing bracket of same type of opening bracket
        else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if(stk.isEmpty() == 1)
                return false;
            else
            {
                char x = stk.stackTop();
                // will give key value pair if that key is found
                itr = mp.find(exp[i]);
                // itr->first is key, itr->second is value
                if(x == itr->second)
                    stk.Pop();
                else
                    return false;
            }
        }
    }

    //Check whether stack is empty or not
    if(stk.isEmpty() == 1)
        return true; // stack is empty
    else
        return false; // stack is Not empty
}



int main()
{

    // exp containing only parenthesis( )
    char a[] = "((a+b)*(c-d))";
    cout<<"is Balanced = "<<isBalanced(a)<<endl;

    // exp containing any of these brackets ( ) { } [ ]
    char b[] = "{([a+b]*[c-d])/e}";   // Y
    char b1[] = "{([a+b]}*[c-d])/e}"; // N
    char b2[] = "{([{a+b]*[c-d])/e}"; // N
    char b3[] = "{[(a+b)*(c-d]]}";    // N

    cout<<endl<<"By Method 1"<<endl;

    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod1(b)<<endl;
    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod1(b1)<<endl;
    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod1(b2)<<endl;
    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod1(b3)<<endl;

    cout<<endl<<"By Method 2"<<endl;

    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod2(b)<<endl;
    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod2(b1)<<endl;
    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod2(b2)<<endl;
    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod2(b3)<<endl;

    cout<<endl<<"By Method 3"<<endl;

    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod3(b)<<endl;
    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod3(b1)<<endl;
    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod3(b2)<<endl;
    cout<<"is Balanced Extended = "<<isBalancedExtendedMethod3(b3)<<endl;

    return 0;
}
