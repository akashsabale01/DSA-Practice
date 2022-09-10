#include <iostream>

using namespace std;

// #define rows 3
// #define columns 3

// int getSum(int m, int n, int arr[][3])
// int getSum(int m, int n, int arr[rows][columns])
int getSum(int m, int n, int **arr)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            sum += arr[i][j];
    }
    return sum;
}

int main()
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int m = 3, n = 3;

    int res = getSum(m, n, arr);
    cout << res;

    return 0;
}