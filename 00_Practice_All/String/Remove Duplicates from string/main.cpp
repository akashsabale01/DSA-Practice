// C++ program to create a unique string using unordered_map

/* access time in unordered_map on is O(1) generally if no collisions occur
and therefore it helps us check if an element exists in a string in O(1)
time complexity with constant space. */

#include <bits/stdc++.h>

using namespace std;

string removeDuplicates(string s)
{
    unordered_map<char, int> exists;

    // Without temp string
    // int index = 0;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (exists[s[i]] == 0) // not found
    //     {
    //         exists[s[i]]++;
    //         s[index++] = s[i];
    //     }
    // }
    // return s.substr(0, index);


    // With temp string
    string temp = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (exists[s[i]] == 0) // not found
        {
            exists[s[i]]++;
            temp += s[i];
        }
    }
    return temp;
}

// driver code
int main()
{
    string s = "geeksforgeeks";
    cout << removeDuplicates(s) << endl;
    return 0;
    
}

// https://www.educative.io/answers/how-to-use-stdstringsubstr-in-cpp
