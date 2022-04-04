/*

-> BubbleSort Algorithm

    T.C = O(n^2), S.C = O(1)

    BubbleSort is Stable i.e. preserves order when duplicates items occurs

    BubbleSort is Adaptive i.e. if given array is already sorted then it takes less time

    Not Suitable for Linked List
*/

#include <iostream>

using namespace std;

void Swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void BubbleSort(int arr[], int n)
{
    int flag = 0; // flag will be useful when given array is already sorted
    for(int i=0; i<n-1; i++) // Loop for pass
    {
        flag = 0;
        for(int j=0; j<n-1-i; j++) // loop for comparision
        {
            if(arr[j] > arr[j+1])
            {
                Swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

void Display(int arr[], int n)
{
    cout<<"Array = ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

int main()
{
    int a[] = {9,2,5,8,22,10,1,7,15,4};
//    int a[] = {2,4,5,7}; // only 1 pass required if array is sorted
    int sz = sizeof(a)/sizeof(a[0]);

    Display(a, sz);

    BubbleSort(a, sz);

    Display(a, sz);

    return 0;
}
