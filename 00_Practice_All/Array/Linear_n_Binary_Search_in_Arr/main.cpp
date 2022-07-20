#include <iostream>
using namespace std;

// Macros
#define forlp(var,s,n) for(int var=s; var<n; ++var)

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
        int linear_Search_Itr(int key);
        int linear_Search_Rec(int key);
        int binary_Search_Itr(int key);
        int binary_Search_Rec(int key);
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

int Array::linear_Search_Itr(int key)
{
    forlp(i,0,len)
    {
        if(key == A[i])
            return i;
    }
    return -1; // not found
}

int helper_linear_Search_Rec(int arr[], int lastIdx, int key)
{
    if(lastIdx < 0) // base case
        return -1;

    if(arr[lastIdx] == key) // Key found
        return lastIdx;

    // Recursive case - Search in remaining array
    return helper_linear_Search_Rec(arr, lastIdx-1, key);
}

int Array::linear_Search_Rec(int key)
{
// Start matching from last element to 0th of array,
//  if Found return its index,
//  else Search in remaining array by neglecting current element i.e. by decreasing size
    int idx = helper_linear_Search_Rec(A, len-1, key);
    return idx;
}

int Array::binary_Search_Itr(int key)
{
    int l=0, h=len-1, mid;

    while(l<=h)
    {
        mid =(l+h)/2;

        if(key == A[mid]) // found
            return mid;

        else if(key < A[mid]) // search in left
            h = mid - 1;

        else if(key > A[mid])
            l = mid + 1;
    }
    return -1; // Not found
}

int helper_binary_Search_Rec(int arr[], int l, int h, int key)
{
    // base case
    if(l>h)
        return -1;

    int mid = (l+h)/2;

    if(key == arr[mid])
        return mid;
    else if(key < arr[mid])
        return helper_binary_Search_Rec(arr, 0, mid-1, key);
    else if(key > arr[mid])
        return helper_binary_Search_Rec(arr, mid+1, h, key);

}


int Array::binary_Search_Rec(int key)
{
    int idx = helper_binary_Search_Rec(A, 0, len-1, key);
    return idx;
}

int main()
{
    Array obj(8);

    obj.Append(1);
    obj.Append(2);
    obj.Append(3);
    obj.Append(4);
    obj.Append(5);
    obj.Append(6);

    obj.Display();

//    cout<<"14's index = "<<obj.linear_Search_Itr(14)<<endl;
//
//    cout<<"14's index = "<<obj.linear_Search_Rec(14)<<endl;

    cout<<obj.binary_Search_Itr(3)<<endl;
    cout<<obj.binary_Search_Rec(3)<<endl;


    return 0;
}
