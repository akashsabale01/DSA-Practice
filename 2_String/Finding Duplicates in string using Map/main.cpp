#include <iostream>
#include <unordered_map>

using namespace std;

string removeDuplicates(string name)
{
    // Method 1 (A) - Use unordered_map<char, int>
    // TC = O(N), SC= O(k) where k is no of unique characters
    // string result;
    // unordered_map<char, int> umap;

    // // Store all character in unordered_map
    // for (char ch : name)
    // {
    //     if (umap[ch] == 0)
    //     {
    //         umap[ch]++;
    //         result += ch;
    //     }
    // }
    // return result;

    // Method 1 (B) - Use unordered_map<char, bool>
    // TC = O(N), SC= O(k) where k is no of unique characters

    // string result;
    // unordered_map<char, bool> umap;

    // // Store all character in unordered_map
    // for (char ch : name)
    // {
    //     if (umap[ch] == false)
    //     {
    //         umap[ch] = true;
    //         result += ch;
    //     }
    // }
    // return result;

    // Method 2- Hashing

    string result;

    int hash[256] = {0};

    for (char ch : name)
    {
        if (hash[ch] == 0) // check whether ascii of char index of hash is 0 or not
        {
            hash[ch]++;
            result += ch;
        }
    }
    return result;
}

int main()
{

    string name = "geeksforgeeks";

    string result = removeDuplicates(name);

    cout << endl;

    cout << result;

    cout << endl;

    return 0;
}
