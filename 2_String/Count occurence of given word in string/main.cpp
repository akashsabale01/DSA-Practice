#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int countOfWord(string paragraph, string word)
{
    stringstream ss(paragraph);
    string token;
    vector<string> tokens;
    while (getline(ss, token, ' ')) // split by space
        tokens.push_back(token);

    int count = 0;
    for (auto token : tokens)
    {
        if (word == token)
            count++;
    }

    return count;
}

int main()
{
    string paragraph = "Make sure you have already create this text file and have some text in it ";
    string word = "text";
    int res = countOfWord(paragraph, word);
    cout << "Count of word = " << res << endl;

    return 0;
}

// https://www.digitalocean.com/community/tutorials/compare-strings-in-c-plus-plus