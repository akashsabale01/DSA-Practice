#include <iostream>

using namespace std;

void FindCountOfWords(char msg[])
{
//    no of words = no of spaces + 1
//    Check whether previous element is Not space i.e. avoid continuous spaces
    int i,noOfSpaces=0;
    for(i=0;msg[i]!='\0';i++)
    {
        if(msg[i]==' ' && msg[i-1]!=' ')
        {
            noOfSpaces++;
        }
    }
    int noOfWords = noOfSpaces+1;
    printf("Count of Words = %d\n",noOfWords);

}

int main()
{
    char msg[] = "How are you";

    FindCountOfWords(msg);

    return 0;
}
