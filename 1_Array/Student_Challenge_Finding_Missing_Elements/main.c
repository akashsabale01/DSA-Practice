#include <stdio.h>
#include <stdlib.h>

// Function for 1st N natural number STARTS FROM 0 to N
// Array must be Sorted for this
void SingleMissingElementFromZero(int a[], int n, int len)
{
    int sum = 0, i;
    for (i = 0; i < len; i++)
        sum += a[i];

    int totalSum = (n * (n + 1)) / 2;
    printf("Missing Element is %d", totalSum - sum);
}

// Function for N natural number NOT start from 0
// Array must be Sorted for this
void SingleMissingElementNotFromZero(int a[], int n)
{
    int l, diff, i;
    l = a[0];
    diff = l - 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] - i != diff)
        {
            printf("Missing Element is %d", i + diff);
            break;
        }
    }
}

// Function for Finding multiple missing elements from array
// Array must be Sorted for this
void MultipleMissingElements(int a[], int n)
{
    int i, diff, l;
    l = a[0];
    diff = l - 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] - i != diff)
        {
            while (diff < a[i] - i)
            {
                printf("Missing Element is %d\n", i + diff);
                diff++;
            }
        }
    }
}

// Function for Finding multiple missing elements from array by Hashing
// Array may or may not be Sorted for this
void MissingElementByHashing(int a[], int n, int l, int h)
{
    //    As you will be using h index of the array array size should be atleast h+1.
    int HashArray[h + 1];
    int i;
    for (i = 0; i < h; i++)
    {
        HashArray[i] = 0;
    }
    // increment hashArray elements at corresponding index
    for (i = 0; i < n; i++)
        HashArray[a[i]]++;
    // check all are 1 if not then that element is missing
    for (i = l; i < h; i++)
    {
        if (HashArray[i] != 1)
        {
            printf("Missing Element is %d\n", i);
        }
    }
}

int main()
{
    int arr1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
    int n = 12, length = 11;
    SingleMissingElementFromZero(arr1, n, length);

    int arr2[] = {6, 7, 9, 10, 11, 12};
    int n = 6;
    SingleMissingElementNotFromZero(arr2, n);

    int arr3[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int n = sizeof(arr3) / sizeof(arr3[0]);
    MultipleMissingElements(arr3, n);

    int arr4[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int n = 10, l = 1, h = 12;
    MissingElementByHashing(arr4, n, l, h);

    return 0;
}
