/*

-> Selection sort Algorithm

    Selection sort is a sorting algorithm that selects the smallest element from an unsorted list in each iteration and places that element at the beginning of the unsorted list.

    T.C = O(n^2), S.C = O(1)

    No of Swaps = O(n)

    Selection sort is Unstable i.e. does not preserves order when duplicates items occurs.

    Selection sort is Not Adaptive i.e. if given array is already sorted then it does NOT takes less time

    After each pass it gives Smallest element
*/

#include <iostream>

using namespace std;

void Swap(int *x, int *y)
{
// When we use pointers to variable and make a function swap, xor methods fails when both pointers point to the same variable, So to avoid this check whether both are not equal while passing address of variables
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;

// Or Use below method for swapping
//    int temp = *x;
//    *x = *y;
//    *y = temp;
}

void SelectionSort(int arr[], int n)
{
    int i,j,k;
    for(i=0; i<n-1; i++) // Loop for Passes
    {
        k = i; // k points to smallest element in remaining array
        for(j=i; j<n; j++) // Loop for checking Smallest element in remaining array
        {
            if(arr[j] < arr[k])
                k = j;
        }
        // cout<<arr[i]<<" "<<arr[k]<<endl; //before swap

        // In case of i==k both pointer will point at same place and hence swap wont work properly. So check below condition
        if(i!=k)
            Swap(&arr[i], &arr[k]); // Swap with Smallest element

        // cout<<arr[i]<<" "<<arr[k]<<endl; //after swap
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

    SelectionSort(a, sz);

    Display(a, sz);

    return 0;
}
