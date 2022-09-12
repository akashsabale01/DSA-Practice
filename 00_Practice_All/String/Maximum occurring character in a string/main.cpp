#include <iostream>
#include <unordered_map>

using namespace std;

char maxOccuringChar(string str)
{
    // Using  unordered_map
    // unordered_map<char, int> umap;
    // int maxFrequency = 0;
    // char maxFreqChar = ' ';

    // for (int i = 0; i < str.size(); i++)
    // {
    //     umap[str[i]]++;
    //     if (umap[str[i]] > maxFrequency)
    //     {
    //         maxFreqChar = str[i];
    //         maxFrequency++;
    //     }
    // }
    // return maxFreqChar;

    // Using Frequency array

    int freq[256] = {0}; // all alphabets, numbers, special chars
    int maxFrequency = 0;
    char maxFreqChar = ' ';

    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i]]++; // storing freq of element to corresponding ascii value
        if (freq[str[i]] > maxFrequency)
        {
            maxFreqChar = str[i];
            maxFrequency++;
        }
    }
    return maxFreqChar;
}

int main()
{
    string str = "gooogle";

    cout << maxOccuringChar(str) << endl;

    return 0;
}