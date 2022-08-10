#include <stdio.h>
#include <stdlib.h>

// Sorted array required
void DuplicateElements(int a[], int n)
{
    if(n==0)
    {
        return ;
    }
    int lastDuplicate = 0;
    int i;
    for(i=0;i<n-1;i++)
    {
        if(a[i] == a[i+1] && a[i]!=lastDuplicate)
        {
            printf("Duplicate element is %d\n",a[i]);
            lastDuplicate = a[i];
        }
    }
}

// Sorted array required
void DuplicateElementsCount(int a[],int n)
{
    int i,j;
    // Move i until n-1
    for(i=0;i<n-1;i++)
    {
        if(a[i] == a[i+1])
        {
            j = i+1;
            while(a[i] == a[j])
            {
                j++;
            }
            printf("%d is appearing %d times\n",a[i],j-i);
            i = j-1;
        }
    }
}

// Sorted array required
void DuplicateElementsCountByHashing(int a[], int n, int h)
{
    // create hashArray of size h+1
    // because for storing h we require h'th index in HashArray
    int hashArray[h+1] = {0};
    int i;

    // increment count for that index in hashArray for respective element of array a
    for(i=0;i<n;i++)
    {
        hashArray[a[i]]++;
    }

    //check for count>1 in hashArray
    for(i=0;i<h+1;i++)
    {
        if(hashArray[i]>1)
        {
            printf("%d is appearing %d times\n",i,hashArray[i]);
        }
    }

}

void DuplicateElementsUnsorted(int a[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        int count = 1;
        if(a[i] != -1)
        {
            for(j=i+1;j<n;j++)
            {
               if(a[i] == a[j])
               {
                   count++;
                   a[j]= -1;
               }
            }
        }
        if(count>1)
        {
            printf("%d is appearing %d times\n",a[i],count);
        }
    }
}

void DuplicateElementsUnsortedByHashing(int a[], int n, int h)
{
    int HashArray[h+1];
    int i;
    for(i=0;i<h+1;i++)
    {
        HashArray[i] = 0;
    }

    for(i=0;i<n;i++)
    {
        HashArray[a[i]]++;
    }

    for(i=0;i<h+1;i++)
    {
        if(HashArray[i]>1)
        {
            printf("%d is appearing %d times\n",i,HashArray[i]);
        }
    }
}

//void DuplicateElementsCount(int a[],int n)
//{
//    int count = 1, lastDuplicate=0;
//    int i;
//    for(i=0;i<n;i++)
//    {
//        if(a[i] == a[i+1])
//        {
//            lastDuplicate = a[i];
//            count++;
//        }
//        else if(a[i+1] !=lastDuplicate && lastDuplicate!=0)
//        {
//            printf("Duplicate element is %d and count is %d\n",lastDuplicate,count);
//        }
//    }
//
//}

void removeDuplicatesUsingUnorderedMap(int arr[], int n)
{
    unordered_map<int, int> umap;

    // for (int i = 0; i < n; i++) // Add key,value pair in unordered_map
    //     umap[arr[i]]++;

    for (int i = 0; i < n; i++)
    {

        // Print element if it is not there in the hash map
        // else increase count i.e. Frequency of that number
        if (umap.find(arr[i]) == umap.end())
        {
            cout << arr[i] << " ";
        }
        umap[arr[i]]++; // increment frequency
    }

    // cout << endl;
    // for (auto ele : umap)
    //     cout << ele.first << " " << ele.second << endl;
}



int main()
{
//    int arr[] = {3,6,8,8,10,11,15,15,15,17,20};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    int h=20;

//    Sorted array required
//    DuplicateElements(arr,n);

// Sorted array required
//    DuplicateElementsCount(arr,n);

// Sorted array required
//    DuplicateElementsCountByHashing(arr,n,h);

    int arr2[] = {8,3,6,4,6,5,6,8,2,7,10};
    int n = sizeof(arr2)/sizeof(arr2[0]);
    int h=10;

// UnSorted or Sorted array required
//    DuplicateElementsUnsorted(arr2,n);

// UnSorted or Sorted array required
    DuplicateElementsUnsortedByHashing(arr2,n,h);

// UnSorted or Sorted array required
removeDuplicatesUsingUnorderedMap(arr2, n);



    return 0;
}
