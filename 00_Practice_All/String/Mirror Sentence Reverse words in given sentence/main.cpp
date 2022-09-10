#include <iostream>
#include <vector>
// #include <istringstream>

using namespace std;

void printVector(vector<string> temp)
{
    for (auto ele : temp)
        cout << ele << " ";
    cout << endl;
}

// 1st Way - Split & merge
string mirrorSentence(string str)
{
    vector<string> wordList;

    str += ' '; // Adding space at last of sentence

    string word = "";

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            wordList.push_back(word);
            word = "";
        }
        else
        {
            word += str[i];
        }
    }

    // printVector(wordList);

    string result = "";
    int sz = wordList.size();
    for (int i = sz - 1; i >= 0; i--)
    {
        // cout << wordList[i];
        if (i == 0)
            result += wordList[i];
        else
            result += wordList[i] + ' ';
    }

    return result;
}

// 2nd way - Reverse entire sentence & then iterate from start if space then reverse word found till this index
string mirrorSentence(string str)
{
}

int main()
{
    string sentence = "Welcome to Cognizant tech";

    string result = mirrorSentence(sentence);

    cout << result;

    return 0;
}

// https://www.geeksforgeeks.org/program-to-reverse-words-in-a-given-string-in-c/