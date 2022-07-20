#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string word)
{
    if(word.length()==0) return false;
    if(word.length()==1) return true;

    string wordReverse = word;

    for(int i=0, j=word.length()-1; i<j; i++, j--)
    {
        // Swap i,j characters
        char tempChar = wordReverse[i];
        wordReverse[i] = wordReverse[j];
        wordReverse[j] = tempChar;
    }

    return (word == wordReverse);
}

void palindromeStrings(string arr[], int arrSize)
{
    vector<string> result;

    for(int i=0; i<arrSize; i++)
    {
        if(isPalindrome(arr[i]))
            result.push_back(arr[i]);
    }

    // Print
    int resSize = result.size();
    for(int i=0; i<resSize; i++)
        cout<<result[i]<<" ";
}

int main()
{
    string arr[] = {"hello", "mam", "dj", "madam", "tenet", "vectro", "", "h"};
    int arrSize = sizeof(arr)/ sizeof(arr[0]);

    palindromeStrings(arr, arrSize);

    return 0;
}
