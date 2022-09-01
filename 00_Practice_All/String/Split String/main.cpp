#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void tokenize(string &givenString, char delim, vector<string> &out)
{
    // construct a stream from the string
    stringstream ss(givenString);

    string s;
    while (getline(ss, s, delim))
    {
        out.push_back(s);
    }
}

int main()
{
    string s = "C C++ Java Python";
    char delim = ' ';

    vector<string> out;
    tokenize(s, delim, out);

    for (auto &s : out)
    {
        cout << s << endl;
    }

    return 0;
}
// https://www.techiedelight.com/split-string-cpp-using-delimiter/