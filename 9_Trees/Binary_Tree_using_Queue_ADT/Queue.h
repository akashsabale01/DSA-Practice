#include <iostream>

using namespace std;

// Node for tree
class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Queue
{
private:
    int Size;
    int Front; // this is index pointer not an address pointer
    int Rear;
    // pointer for creating new array
    // [Node*]*: Pointer to [Pointer to Node]
    Node* *Q;

public:
    Queue();
    Queue(int sz);
    ~Queue();
    void enqueue(Node* x); // storing address of node in queue
    Node* dequeue();
    int isFull();
    int isEmpty();
    void Display();

};

Queue::Queue()
{
    Size = 10;
    Front = -1;
    Rear = -1;
    Q = new Node*[Size];
}

Queue::Queue(int sz)
{
    Size = sz;
    Front = -1;
    Rear = -1;
    Q = new Node*[Size];
}

Queue::~Queue()
{
    delete []Q;
}

int Queue::isEmpty()
{
    if(Front == Rear)
        return 1;

    return 0;
}

int Queue::isFull()
{
    if(Rear == Size-1)
        return 1;

    return 0;
}

void Queue::enqueue(Node* x)
{
    if(isFull() == 1)
        cout<<"Queue is Full"<<endl;
    else
    {
        // Insert at Rear end of queue
        Rear++;
        Q[Rear] = x;
    }
}

Node* Queue::dequeue()
{
    Node* x = NULL;
    if(isEmpty() == 1)
        cout<<"Queue is Empty"<<endl;
    else
    {
        // Delete element from Front end of queue
        Front++;
        x = Q[Front];

    }
    return x;
}

void Queue::Display()
{
    // here we have taken front+1 because front is previous to element
    cout<<endl<<"Queue = ";
    for(int i=Front+1;i<=Rear;i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}


//int main()
//{
////    int sz = 0;
////    cout<<"Enter size of queue = ";
////    cin>>sz;
//
//    Queue q(5);
//
//    q.enqueue(10);
//    q.enqueue(20);
//    q.enqueue(30);
//    q.enqueue(40);
//    q.enqueue(50);
//
//    q.Display();
//
//    cout<<"is Empty = "<<q.isEmpty()<<endl;
//    cout<<"is Full = "<<q.isFull()<<endl;
//
//    cout<<"Deleted element = "<<q.dequeue()<<endl;
//    cout<<"Deleted element = "<<q.dequeue()<<endl;
//
//    q.Display();
//
//    cout<<"is Empty = "<<q.isEmpty()<<endl;
//    cout<<"is Full = "<<q.isFull()<<endl;
//
//    return 0;
//}
