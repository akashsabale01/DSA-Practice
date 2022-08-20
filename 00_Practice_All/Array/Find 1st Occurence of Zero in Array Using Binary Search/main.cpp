//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int Zero1stOccurence(int arr[], int start, int end, int key)
    {
        int mid = (start + end) / 2;

        if (start == end)
        {
            if (arr[mid] == key)
                return mid;
        }

        return Zero1stOccurence(arr, start, mid, key);

        return Zero1stOccurence(arr, mid + 1, end, key);

        return -1;
    }

    int countZeroes(int arr[], int n)
    {

        // Approach 1 - Use Binary Search

        if (n <= 0)
            return 0;

        int firstOccurenceOfZero = Zero1stOccurence(arr, 0, n - 1, 0);

        if (firstOccurenceOfZero == -1)
            return 0;

        int zerosCount = n - firstOccurenceOfZero;

        return zerosCount;

        // Approach 2

        // if(n <= 0)
        //     return 0;

        // int zeroCount = 0;

        // for(int i=n-1; i>=0;i--)
        // {
        //     if(arr[i] == 0)
        //         zeroCount++;
        //     else
        //         break;
        // }
        // return zeroCount;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countZeroes(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

// 1
// 30
// 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0