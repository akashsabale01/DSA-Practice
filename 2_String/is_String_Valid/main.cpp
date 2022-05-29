#include <iostream>

using namespace std;

int isStringValid(char psd[])
{
    int i;
    for(i=0;psd[i]!='\0';i++)
    {
        int isLowerVowel = (psd[i]>=97 && psd[i]<=122);
        int isUpperVowel = (psd[i]>=65 && psd[i]<=90);
        int isDigit = (psd[i]>=48 && psd[i]<=57);
        if(!isLowerVowel && !isUpperVowel && !isDigit)
        {
            return 0;
        }
    }
    return 1;
}


int main()
{

//    ***************String Validation*********************

    char password[10];
    printf("Enter Valid password which is Alphanumberic = ");
    scanf("%s",password);

    if(isStringValid(password))
    {
        printf("%s is Valid",password);
    }
    else
    {
        printf("%s is Not Valid",password);
    }


    return 0;
}
