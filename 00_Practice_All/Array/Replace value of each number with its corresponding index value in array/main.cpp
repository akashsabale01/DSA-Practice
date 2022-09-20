#include <iostream>

using namespace std;

void printArray(int temp[], int n)
{
    for (int i = 0; i < n; i++)
        cout << temp[i] << " ";
    cout << endl;
}

void replaceValueWithIndex(int arr[], int n)
{
    int aux[n] = {0};

    // replace Value(arr[i]) With Index(i)
    for (int i = 0; i < n; i++)
        aux[arr[i]] = i;

    // print
    cout << "Updated Array = ";
    printArray(aux, n);
}

int main()
{
    int arr[4] = {3, 2, 0, 1};
    int n = 4;
    cout << "Original Array = ";
    printArray(arr, n);

    replaceValueWithIndex(arr, n);

    return 0;
}