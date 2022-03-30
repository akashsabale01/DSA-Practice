#include <iostream>

using namespace std;

class Array
{
private:
    int *A;
    int Size;
    int Length;

public:

    Array()
    {
        Size = 10;
        A = new int[Size];
        Length = 0;
    }

    Array(int sz)
    {
        Size = sz;
        A = new int[Size];
        Length = 0;
    }

    ~Array()
    {
        delete []A;
    }

    void Display();
    void Append(int element);

};


void Array::Display()
{
    cout<<"Array is ";
    for(int i=0;i<Length;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void Array::Append(int element)
{
    A[Length] = element;
    Length++;
}

//void Append(int A[], int *len, int element)
//{
//    A[*len] = element;
//    *len += 1;
//}
// Call above in main() fun => Append(arr, &length, 50);

//void Array::Delete(int index)
//{
//
//}



int main()
{
    Array arr(15);
    arr.Append(2);
    arr.Append(4);
    arr.Append(6);
    arr.Append(8);
    arr.Append(10);

    arr.Display();

    return 0;
}
