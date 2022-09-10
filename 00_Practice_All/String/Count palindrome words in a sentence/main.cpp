/*C++ program to count number of palindrome
words in a sentence*/
#include <bits/stdc++.h>
using namespace std;

// Function to check if a word is
// palindrome
bool checkPalin(string word)
{
    int n = word.length();
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (word[i] != word[j])
            return false;
            
    return true;
}

// Function to count palindrome words
int countPalin(string str)
{
    // to check last word for palindrome
    str = str + " ";

    // to store each word
    string word = "";
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // extracting each word
        if (ch != ' ')
            word = word + ch;
        else
        {
            if (checkPalin(word))
                count++;
            word = "";
        }
    }

    return count;
}

// Driver code
int main()
{

    cout << countPalin("Madam Arora teaches malayalam") << endl;

    cout << countPalin("Nitin speaks malayalam") << endl;
}

// This code is contributed by nidhi16bcs2007
