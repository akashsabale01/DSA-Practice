#include <iostream>

using namespace std;

string removeVowel(string text)
{
    // 1st way - using temp string
    // string temp;
    // for (int i = 0; i < text.size(); i++)
    // {
    //     bool isLowerVowel = (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u');
    //     bool isUpperVowel = (text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U');
    //     if (!isLowerVowel && !isUpperVowel)
    //         temp.push_back(text[i]);
    // }
    // return temp;

    // 2nd way - inplace
    // int idx = 0;
    // for (int i = 0; i < text.size(); i++)
    // {
    //     bool isLowerVowel = (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u');
    //     bool isUpperVowel = (text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U');
        
    //     if (!isLowerVowel && !isUpperVowel)
    //         text[idx++] = text[i];
    // }
    // return text.substr(0, idx);

    // 3rd way - In place using substr function

     for (int i = 0; i < text.size(); i++)
    {
        bool isLowerVowel = (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u');
        bool isUpperVowel = (text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U');
        
        if (isLowerVowel || isUpperVowel)
        {
            // substr(start, noOfcharFromStart);
            // 2nd parameter is optional if not given consider all remaining string after start 
            text = text.substr(0,i) + text.substr(i+1);
            i--;
        }
    }
    return text;


}

int main()
{
    // string text = "welcome to geeksforgeeks";
    string text = "take u forward";

    string result = removeVowel(text);

    cout << result;

    return 0;
}