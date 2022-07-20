#include <iostream>
#include <cstring>

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

// char *remove_vowels(char *word)
// {
//     string temp = "";
//     int wordSize = strlen(word);
//     for (int i = 0; i < wordSize; i++)
//     {
//         if (isVowel(word[i]))
//             temp += word[i];
//     }

//     char *res = &temp[0];
//     return res;
// }

string removeVowels(string word)
{
    string res = "";
    int wordSize = word.size();
    for (int i = 0; i < wordSize; i++)
    {
        if (!isVowel(word[i]))
            res += word[i];
    }

    return res;
}

int main()
{

    // char *str = "Hello";

    // char *result = remove_vowels(str);

    // for (int i = 0; i != '\0'; i++)
    //     cout << result[i] << " ";

    string result = removeVowels("babylon");

    cout << result;

    return 0;
}
