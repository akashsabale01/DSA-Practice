//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string modify(string s)
    {
        // Method 1 - Using Temp string
        // TC = O(n) Sc= O(n)
        // string result = "";
        // for(int i=0; i<s.size(); i++)
        // {
        //     if(s[i]==' ')
        //         continue;
        //     else
        //         result += s[i];
        // }
        // return result;

        // Method 2 - Without temp string - Not Working
        // TC= O(N*N)

        // 1) Iterate through all characters of given string, do following
        //     a) If current character is a space, then move all subsequent
        //     characters one position back and decrease length of result string

        // int len = s.size();

        // int i = 0;
        // while (i < len)
        // {
        //     if (s[i] == ' ')
        //     {
        //         // Move all subsequent characters one position back
        //         for (int j = i; j <= len - 2; j++)
        //             s[j] = s[j + 1];

        //         len--; // decrease length of the result string.
        //     }
        //     if (s[i] != ' ')
        //         i++;
        // }

        // string res = "";

        // for (int i = 0; i < len; i++)
        //     res += s[i];

        // return res;

        // Method 3 - Without temp string
        // TC = O(n)
        int nonSpaceCharIndexSoFar = 0;
        int len = s.size();
        for (int i = 0; s[i]; i++)
        {
            if (s[i] != ' ')
                s[nonSpaceCharIndexSoFar++] = s[i];
        }
        return s.substr(0, nonSpaceCharIndexSoFar);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cout << "no of test cases = ";
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cout << "Enter string = ";
        getline(cin, s);
        Solution ob;
        cout << ob.modify(s) << endl;
    }
    return 0;
}

// } Driver Code Ends