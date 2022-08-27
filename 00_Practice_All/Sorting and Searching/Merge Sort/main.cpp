#include <iostream>

using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;

    int auxArr[high + 1];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            auxArr[k++] = arr[i++];
        else
            auxArr[k++] = arr[j++];
    }

    while (i <= mid)
        auxArr[k++] = arr[i++];

    while (j <= high)
        auxArr[k++] = arr[j++];

    for (int p = low; p <= high; p++)
        arr[p] = auxArr[p];
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {3, 2, 1, 5, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}