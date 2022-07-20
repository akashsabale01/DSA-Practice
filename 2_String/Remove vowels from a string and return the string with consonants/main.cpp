#include <iostream>
#include <string>
// #include <cstring>

using namespace std;


string stringWotVowels(string word)
{
    string temp = "";

    
    int sz = word.size();

    for(int i=0; i<sz; i++)
    {
        bool isUpperVowel = (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') ;
        bool isLowerVowel = (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') ;


        if (!isUpperVowel && !isLowerVowel)
            temp += word[i];
    }

    return temp;
}

int main()
{
   string word = "aaabbbeeeccc";
    
    string res = stringWotVowels(word);

    cout<<res;

    return 0;
}
