/*

-> InsertionSort Algorithm

    T.C = O(n^2), S.C = O(1)

    InsertionSort is Stable i.e. preserves order when duplicates items occurs.

    InsertionSort is Adaptive i.e. if given array is already sorted then it takes less time,
    here no need of flag to make adaptive because insertion sort is by default adaptive.

    Suitable for Linked List
*/

#include <iostream>

using namespace std;

void InsertionSort(int arr[], int n)
{
    int j, x;
    for(int i=1; i<n; i++)
    {
        j = i-1;
        x = arr[i];
        while(j>-1 && arr[j]>x) // Loop for Shifting Elements of array
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x; // Inserting element after shifting at its correct position
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

    InsertionSort(a, sz);

    Display(a, sz);

    return 0;
}
