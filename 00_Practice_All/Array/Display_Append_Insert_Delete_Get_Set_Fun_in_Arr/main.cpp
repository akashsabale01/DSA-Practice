#include <iostream>

using namespace std;

class Array
{
private:
     int *A;
     int sz;
     int len;

public:
        Array()
        {
            sz = 10;
            len = 0;
            A = new int[sz];
        }

        Array(int sz)
        {
            sz = sz;
            len = 0;
            A = new int[sz];
        }

        ~Array()
        {
            delete []A;
        }

        void Display();
        void Append(int x);
        void Insert(int index, int x);
        int Delete(int index);
};

void Array::Display()
{
    cout<<"Array = ";
    for(int i=0; i<len; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void Array::Append(int x)
{
    if(len < sz)
        A[len++] = x;
}

void Array::Insert(int index, int x)
{
    if(index < sz && index >=0)
    {
        // Shift element to right & then insert
        for(int i= len; i>index; i--)
            A[i] = A[i-1];
        // insert
        A[index] = x;
        len++;
    }
}

int Array::Delete(int index)
{
    if(index<sz && index>=0)
    {
        // Shift elements to left & then delete
        for(int i=index; i<len; i++)
            A[i] = A[i+1];
        len--;
        return A[index];
    }
    return -1; // Not found;
}

int main()
{
    Array obj(8);

    obj.Append(23);
    obj.Append(12);
    obj.Append(14);
    obj.Append(21);
    obj.Append(7);
    obj.Append(56);

    obj.Display();

//    obj.Insert(2,88);
    obj.Delete(0);

    obj.Display();

    return 0;
}
