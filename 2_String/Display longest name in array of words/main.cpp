// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string longest(string names[], int n)
    {
        string longestString = "";
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            if (names[i].length() > maxLen)
            {
                maxLen = names[i].length();
                longestString = names[i];
            }
        }
        return longestString;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cout << "Enter no of test cases = ";
    cin >> t;
    while (t--)
    {
        int n;
        cout << "Enter size of array = ";
        cin >> n;
        string names[n];

        for (int i = 0; i < n; i++)
        {
            cout << "enter element = ";
            cin >> names[i];
        }
        Solution ob;
        cout << ob.longest(names, n) << endl;
    }
}

// } Driver Code Ends