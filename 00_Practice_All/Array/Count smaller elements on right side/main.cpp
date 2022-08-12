#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

int main()
{
    int arr[] = {12, 10, 5, 4, 2, 20, 6, 1, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *low = (int *)malloc(sizeof(int) * n);

    // constructLowerArray(arr, low, n);
    printArray(low, n);

    return 0;
}

// https://www.geeksforgeeks.org/count-smaller-elements-on-right-side/