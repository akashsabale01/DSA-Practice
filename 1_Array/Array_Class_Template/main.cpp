#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        A = new T[size];
        length = 0;
    }

    Array(int sz)
    {
        size = 10;
        length = 0;
        A = new T[size];
    }

    ~Array()
    {
        delete []A;
    }

    void Display();
    void Insert(int index,T x);
    T Delete(int index);
};

template <class T>
void Array<T>::Display()
{
    cout<<"\nElements are = ";
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";

    cout<<endl;
}

template <class T>
void Array<T>::Insert(int index, T x)
{
    if(index>=0 && index<=length)
    {
        int i;
        // shift elements
        for(i=length-1;i>=index;i--)
            A[i] = A[i-1];

//        cout<<i<<endl;
//        cout<<A[i]<<endl;
//        cout<<A[i-1]<<endl;
        // insert element
        A[index] = x;
        length++;
    }

}

template <class T>
T Array<T>::Delete(int index)
{
    T element = 0;
    if(index>=0 && index<=length)
    {
        element = A[index];
        //shift elements
        for(int i=index;i<length-1;i++)
        {
            A[i] = A[i+1];
            length--;
        }

        // delete element
        return element;
    }
}

int main()
{
    Array<char> obj;

    obj.Insert(0,'a');
    obj.Insert(1,'d');
    obj.Insert(2,'r');
    obj.Insert(3,'y');

    obj.Display();

    cout<<"Deleted element is "<<obj.Delete(2)<<endl;

    obj.Display();

    return 0;
}
