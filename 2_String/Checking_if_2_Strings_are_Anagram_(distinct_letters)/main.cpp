#include <iostream>

using namespace std;

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


int main()
{
// *********Anagram*********

//Anagram is An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “abcd” and “dabc” are an anagram of each other.

    char arr1[]= "verbose";
    char arr2[]= "observe";

    int n1= (sizeof(arr1)/sizeof(arr1[0])) - 1;
    int n2= (sizeof(arr2)/sizeof(arr2[0])) - 1;
    n1--,n2--;

    isAnagramByHashing(arr1,arr2);
    isAnagramByBitwiseOperators(arr1,arr2);


    return 0;
}
