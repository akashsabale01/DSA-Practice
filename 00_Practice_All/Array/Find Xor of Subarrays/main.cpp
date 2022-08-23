/*
    Find XOR of all subarray xors
    i.e. find xor of first subarray then 2nd subarray like for all subarrays
        & then find xor of result of all subarrays

*/
#include <iostream>

using namespace std;

// TC = O(n^3)
// int subarrayXor(int arr[], int n)
// {
//     int res = 0;
//     for (int i = 0; i < n; i++) // i=start of subarray
//     {
//         for (int j = i; j < n; j++) // j=end of subarray
//         {
//             // Loop through Subarray
//             // Do XOR of elements in current subarray
//             for (int k = i; k <= j; k++) // k used for traversing subarray
//             {
//                 res = res ^ arr[k];
//             }
//         }
//     }
//     return res;
// }

// TC = O(n)
int subarrayXor(int arr[], int n)
{
    // initialize result by 0
    // as (a XOR 0 = a)
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int freq = (i + 1) * (n - i);
        // cout << arr[i] << " " << freq << endl;

        // if frequency is odd, then
        // include it in the result
        if (freq % 2 == 1)
            res = res ^ arr[i];
    }
    return res;
}

int main()
{
    int arr[] = {3, 5, 2, 4, 6};
    int n = 5;

    int xorOfAllSubarrayXor = subarrayXor(arr, n);
    cout << xorOfAllSubarrayXor << endl;

    return 0;
}

// https://www.geeksforgeeks.org/xor-subarray-xors/