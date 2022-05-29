#include <iostream>

using namespace std;

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


int main()
{
    char arr[]= "aabbbcccc";

    FindDuplicatesUsingBitWiseOperator(arr);

    return 0;
}
