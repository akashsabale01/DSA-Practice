#include <iostream>

using namespace std;

string largestWord(string str)
{
    string largest = "", tempWord = "";
    int largestFreq = 0;

    // Adding space for last word
    str += " ";

    for (char ch : str)
    {
        if (ch != ' ')
            tempWord += ch;
        else
        {
            if (tempWord.length() > largestFreq)
            {
                largest = tempWord;
                largestFreq = largest.length();
            }
            tempWord = "";
        }
    }
    return largest;
}

int main()
{
    string str = "Google Docs yahoo";

    cout << largestWord(str);

    return 0;
}