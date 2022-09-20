#include <iostream>
#include <vector>

using namespace std;

// Function to find a continuous sub-array which adds up to a given number.
vector<int> subarraySum(vector<int> arr, int n, int targetSum)
{
    // TC = O(N^3) , SC= O(1) - Here space used is negligible
    // vector<int> tempArr;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         int currSum = 0;
    //         for (int k = i; k <= j; k++)
    //         {
    //             currSum += arr[k];
    //         }

    //         if (currSum == targetSum)
    //         {
    //             tempArr.push_back(i + 1); // 1 based indexing,So add 1
    //             tempArr.push_back(j + 1);
    //             return tempArr;
    //         }
    //     }
    // }
    // tempArr.push_back(-1); // Not found
    // return tempArr;

    // Using Prefix Sum Approach
    // TC = O(N^2) , SC= O(1) - Here space used is negligible

    // prefix calculations
    vector<int> prefixArr(n);
    prefixArr[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefixArr[i] = prefixArr[i - 1] + arr[i];

    vector<int> tempArr;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // here i>0 used because here i=0, then prefixArr[i - 1] becames invalid
            int currSum = (i > 0) ? prefixArr[j] - prefixArr[i - 1] : prefixArr[j];

            if (currSum == targetSum)
            {
                tempArr.push_back(i + 1); // 1 based indexing,So add 1
                tempArr.push_back(j + 1);
                return tempArr;
            }
        }
    }
    tempArr.push_back(-1); // Not found
    return tempArr;
}

int main()
{
    vector<int> arr = {1, 2, 3, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 12;

    vector<int> result = subarraySum(arr, n, targetSum);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}

// https://www.javatpoint.com/subarray-with-given-sum
// https://leetcode.com/problems/subarray-sum-equals-k/discuss/1759909/C%2B%2Bor-Full-explained-every-step-w-Dry-run-or-O(n2)-greater-O(n)-or-Two-approaches
// https://leetcode.com/problems/subarray-sum-equals-k/discuss/1382612/C%2B%2B-or-Brute-Force-or-Better-or-Optimal-or-Commented-or-Time-O(N)-or-Auxiliary-Space-O(N)