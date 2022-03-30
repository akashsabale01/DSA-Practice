#include <iostream>

using namespace std;

class CircularQueue
{
private:
    int Size;
    int Front; // this is index pointer not an address pointer
    int Rear;  // this is index pointer not an address pointer
    int *Q; // address pointer for creating new array

public:
    CircularQueue(int sz);
    ~CircularQueue();
    void enqueue(int x);
    int dequeue();
    int isFull();
    int isEmpty();
    void Display();

};

CircularQueue::CircularQueue(int sz)
{
    Size = sz;
    Front = 0;
    Rear = 0;
    Q = new int[Size];
}

CircularQueue::~CircularQueue()
{
    delete [] Q;
}

int CircularQueue::isEmpty()
{
    if(Front == Rear)
        return 1;

    return 0;
}

int CircularQueue::isFull()
{
    if((Rear+1)%Size == Front)
        return 1;

    return 0;
}

void CircularQueue::enqueue(int x)
{
    if(isFull() == 1)
        cout<<"Circular Queue is Full"<<endl;
    else
    {
        // Insert at Rear end of CircularQueue
        Rear = (Rear+1)%Size;
        Q[Rear] = x;
    }
}

int CircularQueue::dequeue()
{
    int x = -1;
    if(isEmpty() == 1)
        cout<<"Circular Queue is Empty"<<endl;
    else
    {
        // Delete element from Front end of CircularQueue
        Front = (Front+1)%Size;
        x = Q[Front];

    }
    return x;
}

//void CircularQueue::Display()
//{
//    // here we have taken front+1 because front is previous to element
//    cout<<endl<<"Circular Queue = ";
//
//    int i=Front+1;
//    do
//    {
//        cout<<Q[i]<<" ";
//        i = (i+1)%Size;
//    }while(i != (Rear+1)%Size);
//
//    cout<<endl;
//}


void CircularQueue::Display()
{
//    int i = (Front + 1)%Size; // initialization should also be with mod size
    int i = Front + 1;

    while (i != (Rear + 1)%Size)
    {
        // should be done with while. if empty nothing should be printed
        cout<<Q[i]<<" ";
        i = (i + 1)%Size;
    }
    cout<<endl;
}

int main()
{
    CircularQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);


    cout<<"Deleted element = "<<q.dequeue()<<endl;

    q.enqueue(6);


    q.Display();

    cout<<"is Empty = "<<q.isEmpty()<<endl;
    cout<<"is Full = "<<q.isFull()<<endl;

//    cout<<"Deleted element = "<<q.dequeue()<<endl;
//    cout<<"Deleted element = "<<q.dequeue()<<endl;

//    q.Display();

    return 0;
}

