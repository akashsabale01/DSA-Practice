// This C++ program will read  a word from user and then count its total occurrence in a text file “file4.txt”.Make sure you have already create this text file and have some text in it. Place this file in the same directory where your program source file is present.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Read from file4.txt
    char ch;
    int alphabetCount = 0, digitCount = 0, whiteSpaces = 0;

    ifstream readObj("file4.txt");
    int i = 0;
    while (readObj)
    {
        readObj.get(ch);

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            alphabetCount++;
        else if (ch == ' ')
            whiteSpaces++;
        else if (ch >= '0' && ch <= '9')
            digitCount++;
    }
    readObj.close();

    cout << endl
         << "Count of Alphabet = " << alphabetCount << endl;
    cout << "Count of Digit = " << digitCount << endl;
    cout << "Count of white spaces = " << whiteSpaces << endl;

    return 0;
}

// https://www.codezclub.com/cpp-count-occurrence-word-using-file-handling/

// input of paragraph
//  A long time ago, in the eastern 44 world, there rose a few civilizations. The 235 main reasons for the rise of these urban civilizations 2 were access to rivers, which served various functions of human beings.