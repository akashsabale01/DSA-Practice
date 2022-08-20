#include <iostream>

using namespace std;

void insertInSortedArray(int arr[], int &len, int capacity, int x)
{
    if (len >= capacity)
        return;

    int idx = len - 1;

    // get correct index's prev index by shifting all greater elements
    while (idx >= 0 && arr[idx] > x)
    {
        arr[idx + 1] = arr[idx];
        idx--;
    }

    arr[idx + 1] = x;
    len++;
}

int main()
{
    int arr[] = {1, 2, 3, 7, 10};
    int capacity = 10, len = 5;

    int x = 29;
    // cout << "Enter element = ";
    // cin >> x;

    insertInSortedArray(arr, len, capacity, x);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";

    return 0;
}