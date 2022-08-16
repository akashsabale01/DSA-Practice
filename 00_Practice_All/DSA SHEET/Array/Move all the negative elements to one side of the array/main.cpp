//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void Swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void segregateElements(int arr[], int n)
    {
        // Approach 1 - Using temp array TC=O(N) SC=O(N)
        // order of elements maintained here

        // int temp[n];
        // int idx =0;

        // for(int i=0; i<n; i++)
        // {
        //     if(arr[i] >=0)
        //         temp[idx++] = arr[i];
        // }

        // for(int i=0; i<n; i++)
        // {
        //     if(arr[i] < 0)
        //         temp[idx++] = arr[i];
        // }

        // for(int i=0; i<n; i++)
        // {
        //     arr[i] = temp[i];
        // }

        // Approach 2 - Using Two Pointer TC=O(N) SC=O(1)
        // But order of elements NOT maintained here

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

        // Approach 2 - Using Quick Sort Partition Process Consider 0 as pivot
        //  TC=O(N) SC=O(1)
        // But order of elements NOT maintained here

        // int pivot = 0, idx = 0;

        // for (int i = 0; i < n; i++)
        // {
        //     // move all positive elements to front
        //     if (arr[i] > pivot)
        //         swap(arr[i], arr[idx++]);
        // }
    }
};

//{ Driver Code Starts.
int main()
{
    // your code goes here
    int t;
    cout << "t = ";
    cin >> t;
    while (t--)
    {
        int n;
        cout << "n = ";
        cin >> n;
        int a[n];
        cout << "array elements = ";
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        ob.segregateElements(a, n);

        cout << "Output = ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}

// } Driver Code Ends

// input
// 1
// 8
// 1 8 1 -1 3 2 -7 -5 11 6