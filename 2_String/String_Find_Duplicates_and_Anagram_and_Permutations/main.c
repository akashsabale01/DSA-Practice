#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FindDuplicatesWotUsingHashing(char A[])
{
    int i,j,count;
    for(i=0;A[i]!='\0';i++)
    {
        count = 1;
        if(A[i]!= -1)
        {
            for(j=i+1;A[j]!='\0';j++)
            {
                if(A[i]==A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
        }
        if(count>1)
        {
            printf("%c is appearing %d times\n",A[i],count);
        }
    }
}

void FindDuplicatesUsingHashing(char A[])
{
//    Here input string must be in Lowercase
    char H[26];
    int i;
    for(i=0;i<26;i++)
    {
        H[i]=0;
    }

    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-97] += 1;
    }

    for(i=0;i<26;i++)
    {
        if(H[i]>1)
        {
            printf("%c is appears %d times\n",97+i,H[i]);
        }
    }

}

void FindDuplicatesUsingBitWiseOperator(char A[])
{
    int H=0,x=0,T=0;
    int i;
    for(i=0;A[i]!='\0';i++)
    {
        x=1;
        x = x<<(A[i]-97);

        if((x&H)>0)
        {
            if((x&T)==0)
            {
                printf("%c is Duplicated\n",A[i]);
                 T=T|x;
            }
        }
        //Merging - Set that bit on in H by performing Bitwise OR operation
        else
        {
            H = x|H;
        }
    }

}

void isAnagramByHashing(char A[],char B[])
{
    if(strlen(A)!=strlen(B))
    {
        printf("Not an Anagram\n");
        return;
    }

    int HashArray[26] = {0};
    int i;

    for(i=0;A[i]!='\0';i++)
    {
        HashArray[A[i]-97] += 1;
    }

    for(i=0;B[i]!='\0';i++)
    {
        HashArray[B[i]-97] -= 1;
        if(HashArray[B[i]-97]<0)
        {
            printf("Not an Anagram\n");
            break;
        }
    }

    if(B[i]=='\0')
    {
        printf("It's an Anagram\n");
    }
    else
    {
        printf("Not an Anagram\n");
    }

}

//void isAnagramByBitwiseOperators(char A[],char B[])
//{
//    int H=0,x=0,T=0;
//    int i;
//    for(i=0;A[i]!='\0';i++)
//    {
//        x=1;
//        x = x<<(A[i]-97);
//        // Masking - Check whether that bit is ON or Off
//        // by performing Bitwise AND operation
//        if((x&H)>0)
//        {
//            if((x&T)==0)
//            {
//                printf("%c is Duplicated\n",A[i]);
//                 T=T|x;
//            }
//        }
//        //Merging - Set that bit on in H by performing Bitwise OR operation
//        else
//        {
//            H = x|H;
//        }
//    }
//
//
//}


void PermutationsOfString(char s[], int k)
{
    static int FreqArr[10] = {0};
    static char Res[10];

    int i;

    if(s[k]=='\0')
    {
        Res[k] = '\0';
        printf("%s\n",Res);
    }
    else
    {
        for(i=0;s[i]!='\0';i++)
        {
            if(FreqArr[i] == 0)
            {
                Res[k] = s[i];
                FreqArr[i] = 1;
                PermutationsOfString(s,k+1);
                FreqArr[i] = 0;
            }
        }
    }
}

void swap(char* a, char* b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void PermutationsOfStringBySwapping(char s[], int l, int h)
{
    int i;
    if(l==h)
    {
        printf("%s\n",s);
    }
    else
    {
        for(i=l;i<=h;i++)
        {
            swap(&s[l],&s[i]);
            PermutationsOfStringBySwapping(s, l+1, h);
            swap(&s[l],&s[i]);
        }
    }
}





int main()
{
//    char arr[]= "aabbbcccc";

//    FindDuplicatesWotUsingHashing(arr);

//    FindDuplicatesUsingHashing(arr);

//    FindDuplicatesUsingBitWiseOperator(arr);

//    char arr1[]= "decimal";
//    char arr2[]= "medical";

// *********Anagram*********

//Anagram is An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “abcd” and “dabc” are an anagram of each other.

//    char arr1[]= "verbose";
//    char arr2[]= "observe";

//    int n1= (sizeof(arr1)/sizeof(arr1[0])) - 1;
//    int n2= (sizeof(arr2)/sizeof(arr2[0])) - 1;
//    n1--,n2--;

//    isAnagramByHashing(arr1,arr2);
//    isAnagramByBitwiseOperators(arr1,arr2);

    char s[] = "ABC";
    PermutationsOfString(s,0);
//    PermutationsOfStringBySwapping(s,0,2);

    return 0;
}
