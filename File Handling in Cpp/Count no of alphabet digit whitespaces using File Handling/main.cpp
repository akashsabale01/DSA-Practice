// This C++ program will read  a word from user and then count its total occurrence in a text file “file4.txt”.
// Make sure you have already create this text file and have some text in it. Place this file in the same directory where your program source file is present.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Write file into file4.txt
    string paragraph;
    cout << "Enter paragraph = ";
    getline(cin, paragraph);

    ofstream myfile("file4.txt");
    if (!myfile)
        cout << "File not created";
    else
    {
        cout << endl
             << "File created successfully!" << endl;
        myfile << paragraph;
        myfile.close();
    }

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

// A long time ago, in the eastern world, there rose a few civilizations. The main reasons for the rise of these urban civilizations were access to rivers, which served various functions of human beings. Along with the Mesopotamian civilization and the Egyptian civilization, rose the Indus Valley civilization spanning Northwest India and modern-day Pakistan. The largest amongst the three civilizations, the Indus Valley civilization flourished around 2600 BC, at which time agriculture in India started flourishing. The fertile Indus valley made it possible for agriculture to be carried out on a large scale. The most well-known towns of the Indus Valley in today’s date are Mohenjo Daro and Harappa. Unearthing these two towns showed excavators glimpses into the richness of the Indus Valley civilization, evidenced in ruins and things like household articles, war weapons, gold and silver ornament - and so on. The people of the Indus Valley civilization lived in well-planned towns and well-designed houses made of baked bricks. In an era of developments and prosperity, civilization, unfortunately, came to an end by around 1300 BC, mainly due to natural calamities.

// ago 213, in the eastern world