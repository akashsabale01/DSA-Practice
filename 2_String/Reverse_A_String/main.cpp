#include <iostream>

using namespace std;

void ReverseStringUsingTempArray(char name[])
{
    for(int i=0;name[i]!='\0';i++){ }

    char tempArray[i+1];
    i = i-1;

    for(int j=0;i>=0;j++,i--)
    {
        tempArray[j] = name[i];
    }
    tempArray[j]='\0';
    printf("Reverse of string = %s\n",tempArray);
}

void ReverseStringWotTempArray(char name[])
{
    char tempvar;
    int i,j;
    for(j=0;name[j]!='\0';j++)
    {
    }
    j = j-1;
    for(i=0;i<j;i++,j--)
    {
        tempvar = name[i];
        name[i] = name[j];
        name[j] = tempvar;
    }
    printf("Reverse of string = %s\n",name);
}


int main()
{
//    ***********Reverse string**********

    char name[] = "Maraan";
    ReverseStringUsingTempArray(name);

    ReverseStringWotTempArray(name);

    return 0;
}
