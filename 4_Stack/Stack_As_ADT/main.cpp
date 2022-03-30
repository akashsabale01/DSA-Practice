#include <iostream>

using namespace std;

class Stack
{
private:
    int Size;
    int top;
    int *s;
public:
    Stack(int sz);
    ~Stack();

    void Display();
    void Push(int dt);
    int Pop();
    int isEmpty();
    int isFull();
    int Peek(int index);
    int stackTop();
};

Stack::Stack(int sz)
{
    Size = sz;
    top = -1;
    s = new int[Size];
}

Stack::~Stack()
{
    delete []s;
}

void Stack::Display()
{
    for(int i=top; i>=0; i--)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}


void Stack::Push(int dt)
{
    if(top == Size-1)
        cout<<"Stack Overflow"<<endl;
    else
    {
        top++;
        s[top] = dt;
    }
}

int Stack::Pop()
{
    int x = -1;
    if(top == -1)
        cout<<"Stack Underflow"<<endl;
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

int Stack::Peek(int index)
{
//  Here top-index+1 is taken,
//  because we have to start peek index from top to bottom of stack
//
//  check whether tmp is valid
//     tmp < 0 ---- this for handling positive numbers greater than size of stack
//     tmp == Size --- this for handling zero
//     tmp > Size --- this for handling negative numbers

    int x = -1;

    int tmp = top-index+1;
    if(tmp < 0 || tmp == Size || tmp>Size)
        cout<<"Invalid Index"<<endl;
    else
    {
        x = s[top-index+1];
    }

    return x;
}

int Stack::isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int Stack::isFull()
{
    if(top == Size-1)
        return 1;
    else
        return 0;
}

int Stack::stackTop()
{
    if(isEmpty())
        return -1;
    else
    {
        // return stack top value
        return s[top];
    }
}

int main()
{
    Stack stk(5);

    stk.Push(10);
    stk.Push(30);
    stk.Push(40);
    stk.Push(70);
    stk.Push(90);

    stk.Display();

//    cout<<"Deleted Element = "<<stk.Pop()<<endl;
//    cout<<"Deleted Element = "<<stk.Pop()<<endl;
//    cout<<"Deleted Element = "<<stk.Pop()<<endl;
//    cout<<"Deleted Element = "<<stk.Pop()<<endl;
//    cout<<"Deleted Element = "<<stk.Pop()<<endl;

//    stk.Display();

//    cout<<"Element is = "<<stk.Peek(2)<<endl;
//    cout<<"Element is = "<<stk.Peek(9)<<endl;
//    cout<<"Element is = "<<stk.Peek(0)<<endl;
//    cout<<"Element is = "<<stk.Peek(-3)<<endl;

//    cout<<"Peek is "<<stk.stackTop()<<endl;

//    cout<<"is Empty = "<<stk.isEmpty()<<endl;
//    cout<<"is Full = "<<stk.isFull()<<endl;


    return 0;
}
