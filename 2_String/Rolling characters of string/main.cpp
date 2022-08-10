/*
You are given a string s,an array roll where roll[i] represents rolling first roll[i] characters in string.
you have to apply every roll[i] on string and output final string.rolling means increasing ASCII value of character. like rolling ‘z’ would result in ‘a’,rolling ‘b’ would result in ‘c’,etc.
constraints: 1<=|s|<=10^5
1<=roll[i]<=10^5

For eg: Input:
bca
3
1 2 3
Output:
eeb


*/

// CPP program to find final
// string after roll operations
#include <bits/stdc++.h>
using namespace std;

// return the final string
// after performing roll operation
// on characters of string

// Method 1 -- Gives TLE in online editor TC = O(n^2), SC= O(1)
// string findRollOut(string s, int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < arr[i]; j++)
//         {
//             s[j] += 1;
//             if (s[j] >= 'z')
//                 s[j] -= 26; // z+1-a = 122+1-97= 26, Hence a = z-26
//         }
//     }
//     return s;
// }

// Method 2-- Working TC = O(n), SC= O(n)

string findRollOut(string s, long long arr[], int n)
{
    // calculate the partial sum first
    /*
        partial sum method
        if A[] = {1,2,3}
        and you have to add a number k to a interval from
        i to j for large no. of queries q

        The best way to do this is
        create a array B[] = {0,0,0} of same size as A[]

        now for every query from 0 to q (given three integers i, j, k)
        B[i] += k
        B[j+1] -=k

        run a loop for B[]
        B[i] += B[i-1]

        The final values of array A[] is
        A[i] = A[i] + B[i]
    */
    int brr[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        brr[0] += 1;
        brr[arr[i]] -= 1;
    }
    for (int i = 1; i < n; i++)
    {
        brr[i] += brr[i - 1];
    }

    // change the string according to number
    // of roll operations in brr array

    // s[i] to rolled brr[i] times
    char ch[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < n; i++)
    {
        int x = brr[i] % 26;
        int y = s[i] - 97;
        s[i] = ch[(x + y) % 26];
    }
    return s;
}

//--- Method 3 Working  TC = O(n), SC= O(n)
// string findRollOut(string s, long long arr[], int n)
// {
//     long long int hash[n + 2] = {0};
//     for (int i = 0; i < n; i++)
//         hash[arr[i]]++;
//     for (int i = n; i >= 0; i--)
//         hash[i] += hash[i + 1];
//     for (int i = 1; i <= n; i++)
//         s[i - 1] = ((s[i - 1] - 'a') + hash[i]) % 26 + 'a';
//     return s;
// }

// method 4 -- Not working
// string findRollOut(string s, long long arr[], int n)
// {
//     string result = "";
//     for (int i = 0; i < s.size(); i++)
//     {
//         int charOffset = (i < n) ? arr[i] : 0;
//         int asciiOfChar = s[i];
//         if (s[i] >= 'z')
//         {
//             result += asciiOfChar + charOffset;
//             asciiOfChar -= 26;
//         }
//         else
//             result += asciiOfChar + charOffset;
//     }
//     return result;
// }

// driver program
int main()
{
    string s = "zcza";
    int n = 4;

    // roll array
    // int roll[] = {1, 1, 3, 4}; // for method 2
    long long roll[] = {1, 1, 3, 4};
    string res = findRollOut(s, roll, n);
    cout << endl;
    cout << res << endl;
    cout << endl;

    return 0;
}