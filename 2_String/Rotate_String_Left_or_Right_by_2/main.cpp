//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        string leftRotationStr1 = str1;
        int n1 = leftRotationStr1.size();

        string rightRotationStr1 = str1;
        int n2 = rightRotationStr1.size();

        for (int k = 0; k < 2; k++) // here rotate by 2 in left or right
        {
            // Left Rotation of str1
            char firstChar = leftRotationStr1[0];

            for (int i = 0; i < n1 - 1; i++)
                leftRotationStr1[i] = leftRotationStr1[i + 1];

            leftRotationStr1[n1 - 1] = firstChar;

            // Right Rotation of str1
            char lastChar = rightRotationStr1[n2 - 1];

            for (int j = n2 - 1; j > 0; j--)
                rightRotationStr1[j] = rightRotationStr1[j - 1];

            rightRotationStr1[0] = lastChar;
        }

        return (str2 == leftRotationStr1) || (str2 == rightRotationStr1);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cout << "Enter no of testcases = ";
    cin >> t;
    while (t--)
    {
        string s;
        string b;
        cout << "enter string = ";
        cin >> s >> b;
        Solution obj;
        string result = (obj.isRotated(s, b)) ? "YES" : "NO";
        cout << result << endl;
    }
    return 0;
}

// } Driver Code Ends
