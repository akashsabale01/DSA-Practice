//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string lookandsay(int n)
    {

        /// base case
        if (n == 1)
            return "1";

        // Rec case
        string s = lookandsay(n - 1);

        string result = "";
        int counter = 0, sz = s.size();

        for (int i = 0; i < sz; i++)
        {
            counter++;
            // segregate into groups
            if (i == sz - 1 || s[i] != s[i + 1])
            {
                result = result + to_string(counter) + s[i];
                counter = 0;
            }
        }
        return result;
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
        Solution obj;
        cout << obj.lookandsay(n) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Note
// https://practice.geeksforgeeks.org/problems/decode-the-pattern1138/1
// https://www.youtube.com/watch?v=9fI_26Dl1IA