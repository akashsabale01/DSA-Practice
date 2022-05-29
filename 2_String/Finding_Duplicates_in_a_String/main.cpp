#include <iostream>

using namespace std;

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


int main()
{
    char arr[]= "aabbbcccc";

    cout<<"Duplicates Using Hashing"<<endl;
    FindDuplicatesUsingHashing(arr);

    cout<<"Duplicates Wot Using Hashing"<<endl;
    FindDuplicatesWotUsingHashing(arr);


    return 0;
}
