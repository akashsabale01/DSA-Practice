#include <iostream>
#include <unordered_map>

using namespace std;

int getDupCount(string word)
{
    unordered_map<char, int> umap;

    for (char ch : word)
        umap[ch]++;

    int duplicateCount = 0;
    for (auto ele : umap)
    {
        if (ele.second > 1)
            duplicateCount++;
    }

    return duplicateCount;
}

string wordWithHighestNoOfDuplicates(string str)
{
    string result = ""; // result is word With Highest No Of Duplicates
    string tempWord = "";
    int dupCount = 0;

    // Adding space for last word
    str += " ";

    for (char ch : str)
    {
        if (ch != ' ')
            tempWord += ch;
        else
        {

            if (getDupCount(tempWord) > dupCount)
            {
                result = tempWord;
                dupCount = getDupCount(tempWord);
            }

            tempWord = "";
        }
    }
    if (result.length() == 0)
        return "-1";

    return result;
}

int main()
{
    string str = "cameron blue";

    cout << wordWithHighestNoOfDuplicates(str);

    return 0;
}