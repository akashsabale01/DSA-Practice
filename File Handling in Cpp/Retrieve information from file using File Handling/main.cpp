#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout << endl;
    // Read from file
    char ch;
    ifstream readObj("file2.txt");
    string tempString;
    while (getline(readObj, tempString))
    {
        cout << tempString << endl;
    }
    readObj.close();

    cout << endl;

    return 0;
}