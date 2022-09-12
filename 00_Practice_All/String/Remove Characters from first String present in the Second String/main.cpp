/*
Given two strings, write a program to remove characters from the first string
which are present in the second string.

Input: String str1 = “abcdef”
       String str2 = “cefz”
Output: abd

*/
#include <iostream>
#include <unordered_map>

using namespace std;

bool isPresent(string str, char ch)
{
    for (char ele : str)
    {
        if (ele == ch)
            return true;
    }
    return false;
}

// Approach 1 - Iterate in str1 & find if it present in str2 if not then include
// TC = O(N^2), SC = O(N)
string getUniquestr1(string str1, string str2)
{
    string res = "";
    for (char ch : str1)
    {
        if (!isPresent(str2, ch))
            res += ch;
    }
    return res;
}

// Approach 2 - Iterate in str1 & find if it present in str2 if not then include
// TC = O(N), SC = O(N)
string getUniquestr1ByHashing(string str1, string str2)
{
    unordered_map<char, bool> umap;
    string res = "";
    for (char ch : str2)
        umap[ch] = true;

    for (char ele : str1)
    {
        if (umap[ele] == false) // Not present in str2
            res += ele;
    }
    return res;
}

int main()
{
    string str1("abcdef"), str2("cefz");

    // cout << getUniquestr1(str1, str2);

    // cout << getUniquestr1ByHashing(str1, str2);

    string temp = "abcdzZ1";
    for (char &ch : temp)
    {
        if (ch == 'z')
            ch = 'a';
        else if (ch == 'Z')
            ch = 'A';
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            ch = ch + 1;
    }
    cout << temp;

    return 0;
}