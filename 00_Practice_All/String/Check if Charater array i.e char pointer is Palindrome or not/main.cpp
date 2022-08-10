#include <iostream>
#include <cstring> // for strlen
using namespace std;

char *getReverse(char *word)
{
    // Appoach 1 - Using Swapping Modifying original string
    // for (int i = 0, j = strlen(word) - 1; i < j; i++, j--)
    // {
    //     char temp = word[i];
    //     word[i] = word[j];
    //     word[j] = temp;
    // }
    // return word;

    // Appraoch 2 - Using Temp Memory in heap & passing its address
    int len = strlen(word);
    char *tempArrPtr = new char[len];
    int i, idx = 0;
    for (i = len - 1; i >= 0; i--) // copy word in revese in
        tempArrPtr[idx++] = word[i];

    return tempArrPtr;
}

int main()
{
    // char word[] = "akash";  // Pass directly char array to function, it will work

    // Convert char* to char array
    char *name = "akash";
    int len = strlen(name);
    char *charArr = new char[len];

    for (int i = 0; i < len; i++)
        charArr[i] = name[i];

    char *result = getReverse(charArr);

    cout << "Revese of Word = " << result << endl;

    // Dealloacte allocated memory
    delete[] result;
    delete[] charArr;
    delete result;
    delete charArr;

    return 0;
}
