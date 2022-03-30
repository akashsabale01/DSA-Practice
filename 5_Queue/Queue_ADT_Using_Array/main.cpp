#include <iostream>

using namespace std;

class Queue
{
private:
    int Size;
    int Front; // this is index pointer not an address pointer
    int Rear;
    int *Q; // pointer for creating new array

public:
    Queue(int sz);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    int isFull();
    int isEmpty();
    void Display();

};

Queue::Queue(int sz)
{
    Size = sz;
    Front = -1;
    Rear = -1;
    Q = new int[Size];
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

void Queue::enqueue(int x)
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

int Queue::dequeue()
{
    int x = -1;
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


int main()
{
//    int sz = 0;
//    cout<<"Enter size of queue = ";
//    cin>>sz;

    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.Display();

    cout<<"is Empty = "<<q.isEmpty()<<endl;
    cout<<"is Full = "<<q.isFull()<<endl;

    cout<<"Deleted element = "<<q.dequeue()<<endl;
    cout<<"Deleted element = "<<q.dequeue()<<endl;

    q.Display();

    cout<<"is Empty = "<<q.isEmpty()<<endl;
    cout<<"is Full = "<<q.isFull()<<endl;

    return 0;
}

/*  OUTPUT

Queue = 10 20 30 40 50
is Empty = 0
is Full = 1
Deleted element = 10
Deleted element = 20

Queue = 30 40 50
is Empty = 0
is Full = 1

*/
