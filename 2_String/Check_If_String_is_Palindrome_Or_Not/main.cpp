#include <iostream>

using namespace std;

//int length(char t[])
//{
//    int len = 0;
//    for(int i=0; word[i]!='\0'; i++)
//        len++;
//    return len;
//}

void isPalindromeUsingTempArray(char word[])
{
    for(int i=0; word[i]!='\0'; i++)
    {
    }
    char tempArray[i+1];

    // copy array in reveres manner
    i=i-1;
    for(int j=0;i>=0;j++,i--)
    {
        tempArray[j] = word[i];
    }
    tempArray[j] = '\0';

    // compare tempArray with original word
    for(i=0,j=0;word[i]!='\0'||tempArray[j]!='\0';i++,j++)
    {
        if(tempArray[i] != word[j])
        {
            break;
        }
    }

    if(tempArray[i]==word[j])
    {
        printf("%s is Palindrome",word);
    }
    else
    {
        printf("%s is Not Palindrome",word);
    }
}

void isPalindromeWotUsingTempArray(char word[])
{
    int i,j;
    for(j=0;word[j]!='\0';j++)
    {
    }
    j = j-1;
    for(i=0;i<j;i++,j--)
    {
        if(word[i]!=word[j])
        {
            printf("%s is Not Palindrome\n",word);
            return ;
        }
    }
    printf("%s is Palindrome\n",word);
}


int main()
{
    char word[] = "tenet";
    isPalindromeUsingTempArray(word);
    isPalindromeWotUsingTempArray(word);
    return 0;
}
