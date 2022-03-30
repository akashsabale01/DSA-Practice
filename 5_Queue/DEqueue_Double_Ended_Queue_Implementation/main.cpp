#include <iostream>

using namespace std;

class DEQueue
{
private:
    int Size;
    int Front,Rear;
    int *Q;
public:
    DEQueue(int Sz);
    ~DEQueue();
    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    void display();
    bool isEmpty();
    bool isFull();

};

DEQueue::DEQueue(int sz)
{
    Size = sz;
    Front = -1;
    Rear = -1;
    Q = new int[Size];
}


DEQueue::~DEQueue()
{
    delete [] Q;
}

bool DEQueue::isEmpty()
{
    if(Front == Rear)
        return true;

    return false;
}

bool DEQueue::isFull()
{
    if(Rear == Size-1)
        return true;

    return false;
}

void DEQueue::enqueueFront(int x)
{
    if(Front == -1)
    {
        cout<<"DEQueue Overflow"<<endl;
    }
    else
    {
        Q[Front] = x;
        Front--;
    }
}

void DEQueue::enqueueRear(int x)
{
    if(isFull() == true)
    {
        cout<<"DEQueue Overflow"<<endl;
        return;
    }
    else
    {
        Rear++;
        Q[Rear] = x;
    }

}

int DEQueue::dequeueFront()
{
    int x = -1;
    if(isEmpty() == true)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        Front++;// changes
        x = Q[Front];
    }
    return x;
}

int DEQueue::dequeueRear()
{
    int x = -1;
    if(isEmpty() == true)
    {
        cout<<"DEQueue is Empty"<<endl;
    }
    else
    {
        x = Q[Rear];
        Rear--;
    }
    return x;
}

void DEQueue::display()
{
    if(isEmpty() == true)
        return;

    cout<<"DEQueue = ";
    for(int i=Front+1;i<=Rear;i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}




int main()
{
    DEQueue deq(5);

    deq.enqueueRear(1);
    deq.enqueueRear(2);
    deq.enqueueRear(3);
    deq.enqueueRear(4);
//    deq.enqueueRear(5);

    deq.dequeueFront(); // making empty space for insert from front
    deq.dequeueFront(); // making empty space for insert from front
    // if empty space is there in front then we can insert from front
    // otherwise if no space available then it will give DEQueue Overflow as output
    deq.enqueueFront(14);
    deq.enqueueFront(15);
    deq.enqueueFront(16);



//    cout<<"Deleted element = "<<deq.dequeueFront()<<endl;
//    cout<<"Deleted element = "<<deq.dequeueFront()<<endl;

//    cout<<"Deleted element = "<<deq.dequeueRear()<<endl;
//    cout<<"Deleted element = "<<deq.dequeueRear()<<endl;

    deq.display();



    return 0;
}
