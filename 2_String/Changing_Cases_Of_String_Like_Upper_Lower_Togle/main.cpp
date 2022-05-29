#include <iostream>

using namespace std;

void UpppercaseToLowercase(char inpstring[])
{
    // add 32 to Upper which will convert Upper to Lower
    int i;
    for(i=0;inpstring[i]!='\0';i++)
    {
        if(inpstring[i]>=65 && inpstring[i]<=90)
        {
            inpstring[i] += 32;
        }
    }
    printf("Lowercase is %s\n",inpstring);
}

void LowercaseToUpppercase(char inpstring[])
{
    // Subtract 32 to Lower which will convert Lower to Upper
    int i;
    for(i=0;inpstring[i]!='\0';i++)
    {
        if(inpstring[i]>=97 && inpstring[i]<=122)
        {
            inpstring[i] -= 32;
        }
    }
    printf("Uppercase is %s\n",inpstring);
}

void ToggleCase(char inpstring[])
{
    int i;
    for(i=0;inpstring[i]!='\0';i++)
    {
        // isUpper
        if(inpstring[i]>=65 && inpstring[i]<=90)
        {
            inpstring[i] += 32;
        }
        //isLower
        else if(inpstring[i]>=97 && inpstring[i]<=122)
        {
            inpstring[i] -= 32;
        }
    }
    printf("ToggleCase is %s\n",inpstring);
}



int main()
{
// ********Changing cases*********
//  here we are using ASCII symbols i.e. A65-Z90, a97-z122

    char greet1[] = "movie";
    LowercaseToUpppercase(greet1);

    char greet2[] = "FOOTBALL";
    UpppercaseToLowercase(greet2);

    char greet3[] = "WeLcOmE";
    ToggleCase(greet3);

    return 0;
}
