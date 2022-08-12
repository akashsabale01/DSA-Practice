#include <iostream>

using namespace std;

string removeVowel(string text)
{
    // 1st way - using temp string
    // string temp;
    // for (int i = 0; i < text.size(); i++)
    // {
    //     bool isLowerAlpha = (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u');
    //     bool isUpperAlpha = (text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U');
    //     if (!isLowerAlpha && !isUpperAlpha)
    //         temp.push_back(text[i]);
    // }
    // return temp;

    // 2nd way - inplace
    int idx = 0;
    for (int i = 0; i < text.size(); i++)
    {
        bool isLowerAlpha = (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u');
        bool isUpperAlpha = (text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U');
        if (!isLowerAlpha && !isUpperAlpha)
            text[idx++] = text[i];
    }
    return text.substr(0, idx);
}

int main()
{
    string text = "welcome to geeksforgeeks";

    string result = removeVowel(text);

    cout << result;

    return 0;
}