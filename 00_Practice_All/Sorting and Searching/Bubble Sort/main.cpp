#include <iostream>

using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// TC = O(N^2) , SC = O(1)
void bubbleSort(int arr[], int n)
{
    bool isSwapped;
    for (int i = 0; i < n; i++)
    {
        isSwapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if (isSwapped == false)
            break;
    }
}

int main()
{
    int arr[] = {4, 1, 3, 7, 2};

    bubbleSort(arr, 5);

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}