#include <stdio.h>
#include <stdlib.h>

void FindMinMax(int a[],int n)
{
    int i,max,min;
    max = a[0];
    min = a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<min)
        {
            min = a[i];
        }
        else if(a[i]>max)
        {
            max = a[i];
        }
    }
    printf("Max is %d\n",max);
    printf("Min is %d\n",min);
}

int main()
{
    int arr[]= {4,8,1,88,33,99,-6,44,6,-1,0};
//    int arr1[]= {2,5,7,9,11,24,37,40,67,88};
//    int arr2[]= {99,88,54,51,47,42,32,21,19};

    int n = sizeof(arr)/sizeof(arr[0]);

    FindMinMax(arr,n);

    return 0;
}
