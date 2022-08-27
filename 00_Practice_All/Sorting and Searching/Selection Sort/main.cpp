#include <iostream>

using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/*
    In Selection sort,
        1st we pick min element at put it at index 0
        then again pick min element at put it at index 1
        Repeat this step until array becames sorted
*/

// TC = O(N^2) , SC = O(1)
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // n-1 passes
    {
        int minIdx = 0;

        for (int j = 0; j < n; j++) // Find Index of Miniumum element
        {
            if (arr[j] < arr[i])
                minIdx = j;
        }

        Swap(arr[i], arr[minIdx]);
    }
}

int main()
{
    int arr[] = {4, 1, 3, 7, 2};

    selectionSort(arr, 5);

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}