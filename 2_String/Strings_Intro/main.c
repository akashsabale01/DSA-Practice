#include <stdio.h>
#include <stdlib.h>

void stringLength(char name[])
{
    int i;
    // iterate string till '\0' character is found
    for(i=0;name[i]!='\0';i++)
    {}
    printf("Length of %s is %d\n",name,i);
}

void UpppercaseToLowercase(char inpstring[])
{
    // add 32 to Upper which will convert to lower
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
    // Subtract 32 to Lower which will convert to Upper
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
        if(inpstring[i]>=65 && inpstring[i]<=90)
        {
            inpstring[i] += 32;
        }

        else if(inpstring[i]>=97 && inpstring[i]<=122)
        {
            inpstring[i] -= 32;
        }
    }
    printf("ToggleCase is %s\n",inpstring);
}

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

void ReverseStringUsingTempArray(char name[])
{
    int i,j;
    for(i=0;name[i]!='\0';i++)
    {
    }
    char tempArray[i+1];
    i = i-1;
    for(j=0;i>=0;j++,i--)
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

void isPalindromeUsingTempArray(char word[])
{
    int i,j;
    for(i=0;word[i]!='\0';i++)
    {
    }
    char tempArray[i+1];

    // copy array in reveres manner
    i=i-1;
    for(j=0;i>=0;j++,i--)
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
    // char
//    char gender = 'a';
//    printf("%c",gender);
//    printf("%d",gender);

    // character array
//    char arr[5] = {'a','b','c','d'};
//    char arr1[] = {'a','b','c','d'};
//    char arr2[] = {97,98,99,100};

//    printf("%s",arr1);


    // string & creating string
    // here \0 is delimiter i.e. string terminator
//    char name[] = {'J','h','o','n','\0'};
//    char name1[] = "John";

//    char FullName1[15];
//    char FullName2[15];

// scanf() take input string upto space , So output is first name only
//    printf("Enter your Full name = ");
//    scanf("%s",FullName1);
//    printf("By scanf() Fullname is %s\n",FullName1);

// gets() is used to take input string with space, So output is both first & lastname
//    printf("Enter your Full name = ");
//    gets(FullName2);
//    printf("By gets() function Fullname is %s\n",FullName2);

// *********Find length of string*********
//    char name[] = "Akash";
//    stringLength(name);

// ********Changing cases*********
//  here we are using ASCII symbols i.e. A65-Z90, a97-z122

//    char greet1[] = "movie";
//    LowercaseToUpppercase(greet1);
//
//    char greet2[] = "FOOTBALL";
//    UpppercaseToLowercase(greet2);
//
//    char greet3[] = "WeLcOmE";
//    ToggleCase(greet3);

//**********Find Count of Vowels & Vowels and words*********

//    char msg[] = "How are you";
//    FindCountOfVowelsAndConsonats(msg);
//    FindCountOfWords(msg);

//    ***************String Validation*********************

//    char password[10];
//    printf("Enter Valid password which is Alphanumberic = ");
//    scanf("%s",password);
//
//    if(isStringValid(password))
//    {
//        printf("%s is Valid",password);
//    }
//    else
//    {
//        printf("%s is Not Valid",password);
//    }

//    ***********Reverse string**********

//    char name[] = "Maraan";
//    ReverseStringUsingTempArray(name);
//    ReverseStringWotTempArray(name);

// *********Compare Strings**********

//    char s1[] = "Painter";
//    char s2[] = "Painting";
//    CompareString(s1,s2);

//********Palindrome*********

    char word[] = "tenet";
    isPalindromeUsingTempArray(word);
//    isPalindromeWotUsingTempArray(word);




    return 0;
}

//When you write
//char stack[] = "hello";
//you are creating a new auto ("stack") variable of type "6-element array of char" (size is taken from  the length of the string literal), and the contents of the string literal "hello" are copied to it.
//
//When you write
//char *heap = "hello";
//you are creating a new auto ("stack") variable of type "pointer to char", and the address of the string literal "hello" is copied to it.
