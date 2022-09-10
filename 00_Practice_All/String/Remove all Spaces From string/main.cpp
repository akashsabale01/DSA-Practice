#include <iostream>
#include <string>

using namespace std;

// For string
string removeSpaces(string str)
{
    int idx = 0;
    for (char ch : str)
    {
        if (ch != ' ')
            str[idx++] = ch;
    }
    return str.substr(0, idx);
}

// For Char array string
// string removeSpaces(char str[])
// {
//     int count = 0; // spaces seen so far

//     for (int i = 0; str[i]; i++)
//         if (str[i] != ' ')
//         {                        // if whitespace is present
//             str[count] = str[i]; // remove whitespace
//             count++;             // increment the count
//         }

//     str[count] = '\0';

//     return str;
// }

int main()
{
    string line = "That is exactly what I was looking to do";
    // char line[] = "That is exactly what I was looking to do";

    cout << removeSpaces(line);

    // string lineSpaceFree = line.replaceAll("[aeiouAEIOU]", "").trim();

    return 0;
}