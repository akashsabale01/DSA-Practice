#include <iostream>

using namespace std;

/*
    In Insertion sort, take 0th element as sorted array , remaining as unsorted array
    pick element from unsorted array & put it in its correct position in sorted array by Shifting array element which are greater
*/

// TC = O(N^2) , SC = O(1)
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        // Shift Greater Elements till correct position found
        while (j > -1 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

int main()
{
    int arr[] = {4, 1, 3, 7, 2};

    insertionSort(arr, 5);

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}