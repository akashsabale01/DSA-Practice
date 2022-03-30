#include <iostream>
#include <stack>

using namespace std;

class QueueUsing2Stack
{
private:
    stack<int> e_stack;
    stack<int> d_stack;
public:
    void enqueue(int x);
    int dequeue();
    void display();
};


void QueueUsing2Stack::enqueue(int x)
{

        e_stack.push(x);
}

int QueueUsing2Stack::dequeue()
{
    int x= -1;
    if(d_stack.empty())
    {
        if(e_stack.empty())
        {
            cout<<"Queue underflow"<<endl;
            return x;
        }
        else
        {
            while(!e_stack.empty())
            {
                d_stack.push(e_stack.top());
                e_stack.pop();
            }
        }
    }
    x = d_stack.top();
    d_stack.pop();
    return x;
}

void QueueUsing2Stack::display()
{
    stack<int> cEstack = e_stack;
    stack<int> cDstack = d_stack;

    while(!cDstack.empty())
    {
        cout<<cDstack.top()<<" ";
        cDstack.pop();
    }

    while(!cEstack.empty())
    {
        cDstack.push(cEstack.top());
        cEstack.pop();
    }

    while(!cDstack.empty())
    {
        cout<<cDstack.top()<<" ";
        cDstack.pop();
    }
    cout<<endl;
}


int main()
{
    QueueUsing2Stack q;

    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

//    q.display();

    cout<<"Deleted element = "<<q.dequeue()<<endl;
    cout<<"Deleted element = "<<q.dequeue()<<endl;
    cout<<"Deleted element = "<<q.dequeue()<<endl;
//    cout<<"Deleted element = "<<q.dequeue()<<endl;

    q.display();

//    int A[] = {1, 3, 5, 7, 9};
//    int n = sizeof(A)/sizeof(A[0]) ;
//
//    QueueUsing2Stack q;
//
//    cout << "Enqueue: ";
//    for (int i=0; i<n; i++){
//        q.enqueue(A[i]);
//        cout << A[i];
//        if (i < n-1){
//            cout << " <- ";
//        }
//    }
//    cout << endl;
//
//    cout << "Dequeue: ";
//    for (int i=0; i<n; i++){
//        cout << q.dequeue();
//        if (i < n-1){
//            cout << " <- ";
//        }
//    }



    return 0;
}
