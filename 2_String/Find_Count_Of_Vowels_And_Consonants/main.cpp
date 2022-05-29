#include <iostream>

using namespace std;

void FindCountOfVowelsAndConsonats(char msg[])
{
    int i,VowelCount=0,ConsonantCount=0;
    for(i=0;msg[i]!='\0';i++)
    {
        int isLowerVowel = (msg[i]=='a'||msg[i]=='e'||msg[i]=='i'||msg[i]=='o'||msg[i]=='u');
        int isUpperVowel = (msg[i]=='A'||msg[i]=='E'||msg[i]=='I'||msg[i]=='O'||msg[i]=='U');
        if(isLowerVowel || isUpperVowel)
        {
            VowelCount++;
        }
        else if((msg[i]>=65 && msg[i]<=90)||(msg[i]>=97 && msg[i]<=122))
        {
            ConsonantCount++;
        }
    }
    printf("Count of Vowel = %d\n",VowelCount);
    printf("Count of Consonant = %d\n",ConsonantCount);
}


int main()
{
//**********Find Count of Vowels & Vowels and words*********

    char msg[] = "How are you";

    FindCountOfVowelsAndConsonats(msg);

    return 0;
}
