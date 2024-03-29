//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1, string s2)
    {
        // Approach 1 - Performing Left and Right rotation till size of string 1 &
        //              checking if Left/right rotation equals to string 2

        // if (s1.size() != s2.size())
        //     return false;

        // string lRotation = s1;
        // int sizeLRotation = lRotation.size();

        // string rRotation = s1;
        // int sizeRRotation = rRotation.size();

        // for (int k = 0; k < s1.size(); k++)
        // {
        //     // Left Rotatation on str1
        //     char firstChar = lRotation[0];

        //     for (int i = 0; i < sizeLRotation - 1; i++)
        //     {
        //         lRotation[i] = lRotation[i + 1];
        //     }

        //     lRotation[sizeLRotation - 1] = firstChar;

        //     if (lRotation == s2)
        //         return true;

        //     //  // Right Rotatation on str1
        //     char lastChar = rRotation[sizeRRotation - 1];

        //     for (int i = sizeRRotation - 1; i > 0; i--)
        //     {
        //         rRotation[i] = rRotation[i - 1];
        //     }

        //     rRotation[0] = lastChar;

        //     if (rRotation == s2)
        //         return true;
        // }

        // return false;

        // Approach 2 - check if string 2 is Substring of string1+string1

        if (s1.size() != s2.size())
            return false;

        string temp = s1 + s2;

        return (temp.find(s2) != string::npos);
        // string::npos actually means until the end of the string
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution obj;
        string result = (obj.areRotations(s1, s2)) ? "yes" : "no";
        cout << result << endl;
    }
    return 0;
}

// } Driver Code Ends