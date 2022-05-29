#include <iostream>

using namespace std;

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

void Swap(char* a, char* b)
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
            Swap(&s[l],&s[i]);
            PermutationsOfStringBySwapping(s, l+1, h);
            Swap(&s[l],&s[i]);
        }
    }
}


int main()
{
    char s[] = "ABC";

    PermutationsOfString(s,0);

    cout<<endl;

    PermutationsOfStringBySwapping(s,0,2);

    return 0;
}
