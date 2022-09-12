#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// TC = O(N*Logn) SC = O(1)
// bool areAnagram(string s1, string s2)
// {
//     if (s1.length() != s2.length())
//         return false;

//     sort(s1.begin(), s1.end());
//     sort(s2.begin(), s2.end());

//     return s1 == s2;
// }

// TC = O(N) SC = O(N)
// bool areAnagram(string s1, string s2)
// {
//     if (s1.length() != s2.length())
//         return false;

//     unordered_map<char, int> umap;

//     for (int i = 0; i < s1.length(); i++)
//     {
//         umap[s1[i]]++;
//         umap[s2[i]]--;
//     }

//     for (auto ele : umap)
//     {
//         if (ele.second != 0)
//             return false;
//     }
//     return true;
// }

// TC = O(N) SC = O(1)
bool areAnagram(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'A']++;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        freq[s2[i] - 'A']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string s1("CAT"), s2("TAC");

    string res = (areAnagram(s1, s2)) ? "Yes" : "No";
    cout << res;

    return 0;
}