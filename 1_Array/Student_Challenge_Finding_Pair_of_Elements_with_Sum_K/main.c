#include <stdio.h>
#include <stdlib.h>

void ElementsPairHavingSumK(int a[],int n, int k)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]+a[j] == k)
            {
                printf("%d + %d = %d\n",a[i],a[j],k);
            }
        }
    }
}

void ElementsPairHavingSumKByHashing(int a[], int n, int h, int k)
{
    int HashArray[h+1] = {0};
    int i;
    for(i=0;i<n;i++)
    {
        if(HashArray[k-a[i]] == 1)
        {
            printf("%d + %d = %d\n",a[i],k-a[i],k);
        }
        HashArray[a[i]]++;
    }
}

void ElementsPairHavingSumKInSortedArr(int a[],int n, int k)
{
    int i=0,j=n-1;
    while(i<j)
    {
        if(a[i]+a[j]==k)
        {
            printf("%d + %d = %d\n",a[i],a[j],k);
            i++,j--;
        }
        else if(a[i]+a[j] > k)
        {
            j--;
        }
        else if(a[i]+a[j] < k)
        {
            i++;
        }
    }
}


int main()
{
//    int arr[] = {6,3,8,10,16,7,5,2,9,14};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    int k = 10, h=16;

//    ElementsPairHavingSumK(arr,n,k);

//    ElementsPairHavingSumKByHashing(arr,n,h,k);

    int arr[] = {1,3,4,5,6,8,9,10,12,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 10;

    ElementsPairHavingSumKInSortedArr(arr,n,k);

    return 0;
}
