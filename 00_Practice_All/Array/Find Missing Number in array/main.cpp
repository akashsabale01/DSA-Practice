#include <bits/stdc++.h>
using namespace std;

int MissingNumber(vector<int> &arr, int n)
{
    if (n <= 0)
        return -1;

    int actualSum = (n * (n + 1)) / 2;

    int currSum = 0;

    for (int i = 0; i < arr.size(); i++) // instead of arr.size(); you can also use n-1 as only one number is missing in range 1 to n
        currSum += arr[i];

    int missingNum = actualSum - currSum;

    return missingNum;
}

int main()
{

    vector<int> arr = {2, 3, 4, 1, 6, 7};
    int n = 7;

    int result = MissingNumber(arr, n);

    if (result == -1)
        cout << "Not Found";
    else
        cout << "Missing Number= " << result;

    return 0;
}