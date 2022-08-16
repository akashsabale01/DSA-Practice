#include <iostream>

using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void segregateElements(int arr[], int n)
{
    int i = 0, j = n - 1;

    while (i <= j)
    {
        if (arr[i] > 0 && arr[j] < 0) // true case p n
            i++, j--;

        else if (arr[i] < 0 && arr[j] > 0) // opposite case  n p
            Swap(arr[i++], arr[j--]);

        else if (arr[i] < 0 && arr[j] < 0)
            j--;

        else if (arr[i] > 0 && arr[j] > 0)
            i++;
    }
}

int main()
{

    int arr[] = {1, -1, 3, 2, -7, -5, 11, 6};
    int n = 8;

    segregateElements(arr, n);

    cout << "Output = ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}