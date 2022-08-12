#include <bits/stdc++.h>

using namespace std;

string getXor(string s1, string s2)
{
    string res;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == s2[i])
            res.push_back('0');
        else
            res.push_back('1');
    }
    return res;
}

void xorBinaryArray(string arr[], int n)
{
    // Find the maximum-sized binary string
    int maxLen = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int currentStringSize = arr[i].size();
        maxLen = (maxLen > currentStringSize) ? maxLen : currentStringSize;
        reverse(arr[i].begin(), arr[i].end());
    }
    // cout << maxLen;

    // Make all the binary strings in an array to the size of the maximum sized string,
    // by adding 0s at the Most Significant Bit
    for (int i = 0; i < n; i++)
    {
        string zerosToAdd;
        for (int j = 0; j < maxLen - int(arr[i].size()); j++)
            zerosToAdd += '0';

        arr[i] += zerosToAdd;
    }

    string result = arr[0];
    //  Perform XOR operation on each bit
    for (int i = 1; i < n; i++)
    {
        result = getXor(result, arr[i]);
    }

    reverse(result.begin(), result.end());
    cout << result;
}

int main()
{
    string arr[] = {"1000", "10001", "0011"};
    int n = sizeof(arr) / sizeof(arr[0]);
    xorBinaryArray(arr, n);

    return 0;
}