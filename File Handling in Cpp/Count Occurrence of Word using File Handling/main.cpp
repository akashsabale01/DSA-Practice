#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int occurenceOfWord(string dataOfFile, string wordToSearch)
{
    // Tokenize
    stringstream ss(dataOfFile);
    string token;
    vector<string> tokens;
    while (getline(ss, token, ' '))
        tokens.push_back(token);

    // Search word in vector
    int matchCount = 0;
    for (auto token : tokens)
    {
        if (wordToSearch == token)
            matchCount++;
    }

    return matchCount;
}

int main()
{
    string wordToSearch = "text";

    // Read from file
    ifstream readObj("file4.txt");

    // push file data into a string dataOfFile
    string dataOfFile;
    char ch;
    while (readObj)
    {
        ch = readObj.get();
        dataOfFile.push_back(ch);
    }
    readObj.close();

    int noOfOccurence = occurenceOfWord(dataOfFile, wordToSearch);

    cout << endl;
    cout << "Count of " << wordToSearch << " = " << noOfOccurence << endl;
    cout << endl;

    return 0;
}
// https://www.codezclub.com/cpp-count-occurrence-word-using-file-handling/
// https://www.digitalocean.com/community/tutorials/compare-strings-in-c-plus-plus