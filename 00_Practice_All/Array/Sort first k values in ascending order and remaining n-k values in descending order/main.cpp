#include <iostream>

using namespace std;

void sortArray(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++) // -i for reducing element after each pass
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void printArray(int a[], int sz)
{
    for (int i = 0; i < sz; i++)
        cout << a[i] << " ";
    cout << endl;
}

void printOrder(int arr[], int n, int k)
{
    int len1 = k, len2 = n - k;
    int firstPart[len1], secondPart[len2];

    for (int i = 0; i < len1; i++)
        firstPart[i] = arr[i];

    for (int j = k; j < n; j++)
        secondPart[j - k] = arr[j];

    sortArray(firstPart, len1);
    sortArray(secondPart, len2);

    int revIdx = len2 - 1; // for copying secondPart in reverse
    for (int i = 0; i < n; i++)
    {
        if (i < k)
            arr[i] = firstPart[i];
        else
            arr[i] = secondPart[revIdx--];
    }

    cout << "Result Array : ";
    printArray(arr, n);

    cout << "first Part : ";
    printArray(firstPart, len1);

    cout << "Second Part : ";
    printArray(secondPart, len2);
}

int main()
{
    int arr[9] = {5, 4, 6, 2, 1, 3, 8, 9, -1};
    int n = 9, k = 4;

    printOrder(arr, n, k);

    return 0;
}