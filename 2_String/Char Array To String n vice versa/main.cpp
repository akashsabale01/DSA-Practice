// https://www.geeksforgeeks.org/convert-string-char-array-cpp/

#include <iostream>
#include <string.h>

using namespace std;

bool isVowel(char ch)
{
    bool isUpperVowel = (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    bool isLowerVowel = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');

    if (isUpperVowel || isLowerVowel)
    {
        return true;
    }
    return false;
}

char *removeVowels(char *word)
{
    string temp = "";
    int wordSize = strlen(word);

    // Remove Vowels & store it in temp string
    for (int i = 0; i < wordSize; i++)
    {
        if (!isVowel(word[i]))
            temp += word[i];
    }

    // Convert string to char array(i.e. char pointer)
    int tmpSize = temp.size();
    char *result = new char[tmpSize];

    // Copy elements from temp string to result char array
    for (int i = 0; i < tmpSize; i++)
        result[i] = temp[i];

    result[tmpSize] = '\0'; // Last char as of resultult

    return result;
}

// Method 2 - Using String

// string removeVowels(string word)
// {
//     string res = "";
//     int wordSize = word.size();
//     for (int i = 0; i < wordSize; i++)
//     {
//         if (!isVowel(word[i]))
//             res += word[i];
//     }
//     return res;
// }

int main()
{

    char *str = "Hello";

    char *result = removeVowels(str);

    for (int i = 0; i != '\0'; i++)
        cout << result[i] << " ";

    cout << result;

    return 0;
}
