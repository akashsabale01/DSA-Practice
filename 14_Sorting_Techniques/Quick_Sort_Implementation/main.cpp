/*

-> Quick Sort Algorithm

    Quicksort is a sorting algorithm based on the divide and conquer approach where

    An array is divided into subarrays by selecting a pivot element (element selected from the array).

    While dividing the array, the pivot element should be positioned in such a way that elements less than pivot are kept on the left side and elements greater than pivot are on the right side of the pivot.

    The left and right subarrays are also divided using the same approach. This process continues until each subarray contains a single element.

At this point, elements are already sorted. Finally, elements are combined to form a sorted array.

    T.C = O(n^2) , Best T.C and Avg = O(nlogn),
    S.C = O(logn)

    Quick sort is Unstable i.e. does not preserves order when duplicates items occurs.

    Quick sort is Not Adaptive i.e. if given array is already sorted then it does NOT takes less time

*/

#include <iostream>

using namespace std;

void Display(int arr[], int n)
{
    cout<<"[ ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    cout<<" ]";
    cout<<endl;
}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Partition for Quick Sort using INT_MAX or INFINITY
int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i=low, j=high;

    do
    {
        // Increment i as long as elements are smaller/equal to pivot
        do{i++;}while(arr[i] <= pivot);

        // Decrement j as long as elements are larger than pivot
        do{j--;}while(arr[j] > pivot);

        if(i<j)
            Swap(&arr[i], &arr[j]);

    }while(i<j);

    Swap(&arr[low], &arr[j]);

    return j;
}

// Quick Sort using INT_MAX or INFINITY
void QuickSort(int arr[], int low, int high)
{
    int p; // p is partition position after partition of array
    if(low < high)
    {
        p = Partition(arr,low,high);
        QuickSort(arr,low,p);
        QuickSort(arr,p+1,high);
    }
}


// Partition for QuickSort, Where first Element is Pivot + without using INT_MAX or INFINITY
int PartitionWOTIntMax(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1, j = high;

    while(true)
    {
        while(i <= j && arr[i] <= pivot) { i++; }

        while(arr[j] >= pivot && j >= i) { j--; }

        if(j<i)
            break;
        else
            Swap(&arr[i], &arr[j]);
    }

    Swap(&arr[low], &arr[j]);

    return j;
}

// QuickSort, Where first Element is Pivot + without using INT_MAX or INFINITY
void QuickSortWOTIntMax(int A[], int low, int high)
{
    if (low < high)
    {
        int p = Partition(A, low, high);
        QuickSort(A, low, p-1);
        QuickSort(A, p+1, high);
    }
}

// Partition for QuickSort, Where Last Element is Pivot + without using INT_MAX or INFINITY
int PartitionLast(int A[], int low, int high)
{
    int pivot = A[high];
    int i = low - 1;

    for (int j=low; j<=high-1; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            Swap(&A[i], &A[j]);
        }
    }
    Swap(&A[i+1], &A[high]);
    return i+1;
}

// QuickSort, Where Last Element is Pivot + without using INT_MAX or INFINITY
void QuickSortLast(int A[], int low, int high)
{
    if(low < high)
    {
        int p = PartitionLast(A, low, high); // A[p] in sorted position
        QuickSortLast(A, low, p-1); // Sort elements in range: A[low], A[p-1]
        QuickSortLast(A, p+1, high); // Sort elements in range: A[p+1], A[high]
    }
}


int main()
{
    int nums[] = {9,2,5,8,22,10,1,7,15,4};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << "Given UnSorted Array : "<< endl;
    Display(nums, n);

    cout<<endl<< "Quick Sort Using INT_MAX or Infinity: " << endl;
    int a[] = {9,2,5,8,22,10,1,7,15,4,INT_MAX};
    int sza = sizeof(a)/sizeof(a[0]);
    QuickSort(a,0,sza-1);
    Display(a, sza-1);

    cout<<endl<< "Quick Sort, where First Element as Pivot + w/o INT_MAX or Infinity: " << endl;
    int b[] = {9,2,5,8,22,10,1,7,15,4};
    int szb = sizeof(b)/sizeof(b[0]);
    QuickSortWOTIntMax(b,0,szb);
    Display(b, szb);

    cout<<endl<< "Quick Sort, where Last Element as Pivot + w/o INT_MAX or Infinity: " << endl;
    int c[] = {9,2,5,8,22,10,1,7,15,4};
    int szc = sizeof(c)/sizeof(c[0]);
    QuickSortLast(c,0,szc-1);
    Display(c, szc);

    return 0;
}
