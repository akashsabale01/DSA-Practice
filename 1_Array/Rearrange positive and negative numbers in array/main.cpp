#include <iostream>
using namespace std;

// Approach 1 - Arrange Negative values wrt pivot=0
// TC= O(n), SC= O(1)
// note- here Order not Mainted

// void swap(int &a, int &b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// void rearrange(int arr[], int n)
// {
//     int negIdx = 0;
//     int pivot = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] < pivot) // Arrange Negative values wrt pivot=0
//         {
//             swap(arr[negIdx], arr[i]);
//             negIdx++;
//         }
//     }
// }

// Approach 2 - Use temp array
// TC= O(n), SC= O(n)
// note- here Order Mainted

// void rearrange(int arr[], int n)
// {
//     int temp[n] = {0};
//     int negIdx = 0;
//     // Store -ve values in temp array
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] < 0)
//             temp[negIdx++] = arr[i];
//     }
//     // If array contains all negative or no negative values.
//     if (negIdx == n || negIdx == 0)
//         return;
//     // Store +ve values in temp array
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] >= 0)
//             temp[negIdx++] = arr[i];
//     }
//     // Copy contents of temp[] to arr[]
//     for (int i = 0; i < n; i++)
//         arr[i] = temp[i];
// }

// Approach 3 - Use temp array
// TC= O(n), SC= O(1)
// note- here Order Mainted

void rearrange(int arr[], int n)
{
    int aux[n];

    for (int i = 0; i < n; i++)
        aux[i] = arr[i];

    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = aux[i];

        //  if the current element is positive, traverse to the next element in the array.
        if (temp > 0)
            continue;

        // If the current element is negative, right shift the positive elements by one position
        // and insert the negative number in current position.

        j = i - 1;
        while (aux[j] > 0 && j >= 0)
        {
            aux[j + 1] = aux[j]; // Right shift
            j--;
        }

        aux[j + 1] = temp;
    }
}

void printArr(int arr[], int sz)
{
    cout << "Array = ";

    for (int i = 0; i < sz; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    int arr[5] = {2, -1, 3, -5, 4};
    int n = 5;

    rearrange(arr, n);

    printArr(arr, n);

    return 0;
}

// Notes
// https://www.faceprep.in/c/rearrange-positive-and-negative-numbers-in-an-array-faceprep/
