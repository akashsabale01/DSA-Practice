/*
Problem Statement: Given a string, write a program to Capitalize the first and last character of each word of that string.

Input: String str = "take u forward is awesome"
Output: “TakE U ForwarD IS AwesomE”

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isLower(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

char toUpper(char ch)
{
    return ch - 32;
}

// string capitalizeChars(string str)
// {
//     int n = str.size();

//     for (int i = 0; i < n; i++)
//     {
//         if ((i == 0 || i == n - 1) && isLower(str[i]))
//             str[i] = toUpper(str[i]);

//         else if (str[i] == ' ')
//         {
//             if (isLower(str[i - 1])) // Update only when curr char is Lower
//                 str[i - 1] = toUpper(str[i - 1]);

//             if (isLower(str[i + 1]))
//                 str[i + 1] = toUpper(str[i + 1]);
//         }
//     }
//     return str;
// }

void printVector(vector<string> &wordList)
{
    for (auto ele : wordList)
        cout << ele << " ";
    cout << endl;
}

void capitalizeChars(string str)
{

    // 1st step - Split given sentence into list of words

    vector<string> wordList;

    str += ' '; // Add Space at last for adding last word in list

    string tempWord = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
            tempWord += str[i];
        else
        {
            wordList.push_back(tempWord);
            tempWord = "";
        }
    }

    printVector(wordList);

    // 2nd step - Making 1st & last as Upper
    for (int i = 0; i < wordList.size(); i++)
    {
        string &tempStr = wordList[i]; // modify given word by using & pass by reference

        if (isLower(tempStr[0]))
            tempStr[0] = toUpper(tempStr[0]);

        int sz = tempStr.size();
        if (isLower(tempStr[sz - 1]))
            tempStr[sz - 1] = toUpper(tempStr[sz - 1]);
    }

    printVector(wordList);
}

int main()
{
    string str = "take u forward is awesome";

    capitalizeChars(str);

    return 0;
}