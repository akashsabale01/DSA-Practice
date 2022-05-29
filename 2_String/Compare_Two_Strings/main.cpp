#include <iostream>

using namespace std;

void CompareString(char str1[], char str2[])
{
    int i,j;
    for(i=0,j=0;str1[i]!='\0'||str2[j]!='\0';i++,j++)
    {
        if(str1[i]!=str2[j])
        {
            break;
        }
    }
    if(str1[i] == str2[j])
    {
        printf("They are equal\n");
    }
    else if(str1[i] < str2[j])
    {
        printf("%s is smaller than %s\n",str1,str2);
    }
    else
    {
        printf("%s is greater than %s\n",str1,str2);
    }
}

int main()
{
// *********Compare Strings**********

    char s1[] = "Painter";
    char s2[] = "Painting";
    CompareString(s1,s2);

    return 0;
}
