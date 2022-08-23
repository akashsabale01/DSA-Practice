#include <iostream>

using namespace std;

int giveXor(int arr[], int n)
{
    if (n <= 0)
        return -1;

    if (n == 1)
        return arr[0];

    int res = arr[0];

    for (int i = 1; i < n; i++)
        res = res ^ arr[i];

    return res;
}

int main()
{
    int arr[] = {2, 4, 8};
    int n = 3;

    int arrXor = giveXor(arr, n);
    cout << arrXor << endl;

    return 0;
}
