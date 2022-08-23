#include <iostream>
#include <vector>

using namespace std;

// TC = O(n^3) --- NOT Working
int subarrayXor(int arr[], int n)
{
    int sumOfSubarraysXors = 0;
    int res = 0;
    for (int i = 0; i < n; i++) // i=start of subarray
    {
        for (int j = i; j < n; j++) // j=end of subarray
        {
            for (int k = i; k <= j; k++) // k used for traversing subarray
            {
                res = res ^ arr[k];
            }
            sumOfSubarraysXors += res;
        }
    }
    return sumOfSubarraysXors;
}

int main()
{
    int arr[] = {1, 3, 7, 9, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int xorOfAllSubarrayXor = subarrayXor(arr, n);
    cout << xorOfAllSubarrayXor << endl;

    return 0;
}

// https://www.geeksforgeeks.org/sum-of-xor-of-all-subarrays/