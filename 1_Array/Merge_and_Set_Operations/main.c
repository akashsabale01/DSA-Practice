#include <stdio.h>
#include <stdlib.h>

struct Array {
     int *A;
     int size;
     int length;
};


void Display(struct Array arr)
{
    int i;
    printf("\nElements are = ");
    for(i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}


struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=0,j=0,k=0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k] = arr1->A[i];
            i++,k++;
        }
        else
        {
           arr3->A[k] = arr2->A[j];
           j++,k++;
        }
    }

    for(;i<arr1->length;i++)
    {
        arr3->A[k] = arr1->A[i];
        k++;
    }

    for(;j<arr2->length;j++)
    {
        arr3->A[k] = arr2->A[j];
        k++;
    }

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}


struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=0,j=0,k=0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k] = arr1->A[i];
            i++,k++;
        }
        else if(arr2->A[j]<arr1->A[i])
        {
           arr3->A[k] = arr2->A[j];
           j++,k++;
        }
        else if(arr1->A[i] == arr2->A[j])
        {
            // both equal then copy only 1 value & increment i,j,k
            arr3->A[k] = arr1->A[i];
            i++,j++,k++;
        }
    }

    for(;i<arr1->length;i++)
    {
        arr3->A[k] = arr1->A[i];
        k++;
    }

    for(;j<arr2->length;j++)
    {
        arr3->A[k] = arr2->A[j];
        k++;
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=0,j=0,k=0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            i++;
        }
        else if(arr2->A[j]<arr1->A[i])
        {
            j++;
        }
        else if(arr1->A[i] == arr2->A[j])
        {
            // both equal then copy only 1 value & increment i,j,k
            arr3->A[k] = arr1->A[i];
            i++,j++,k++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


struct Array* SetDifference(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=0,j=0,k=0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k] = arr1->A[i];
            i++,k++;
        }
        else if(arr2->A[j]<arr1->A[i])
        {
           j++;
        }
        else if(arr1->A[i] == arr2->A[j])
        {
            // both equal then ignore
            i++,j++;
        }
    }

    for(;i<arr1->length;i++)
    {
        arr3->A[k] = arr1->A[i];
        k++;
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


int isSetMemberLinearSearch(struct Array arr,int key)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        if(key == arr.A[i])
        {
            return 1;
        }
    }

    return 0;
}


int isSetMemberBinarySearch(struct Array arr,int key)
{
    int i,l,mid,h;
    l=0;
    h=arr.length;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return 1;
        else if(key<arr.A[mid])
            h=mid-1;
        else if(key>arr.A[mid])
            l=mid+1;
    }

    return 0;
}

int isSetMemberLinearSearchForUnion(struct Array *arr,int key)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key == arr->A[i])
        {
            return 1;
        }
    }

    return 0;
}


struct Array* UnionWOTMerge(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    k=0;

    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    for(i=0;i<arr1->length;i++)
    {
        arr3->A[k] = arr1->A[i];
        k++;
    }

    for(j=0;j<arr2->length;)
    {
        if(isSetMemberLinearSearchForUnion(&arr3,arr2->A[j]) != 1 )
        {
            arr3->A[k] = arr2->A[j];
            j++,k++;
        }
        else
        {
            j++;
        }
    }

    return arr3;
};


int main() {

    struct Array arr1 = {{2,5,8,10,12},10,5};
    struct Array arr2 = {{1,5,6,10,19},10,5};
    struct Array *arr3;

//    arr3 = Merge(&arr1,&arr2);

//    arr3 = Union(&arr1,&arr2);

//    arr3 = Intersection(&arr1,&arr2);

//    arr3 = SetDifference(&arr1,&arr2);

//    printf("is Member = %d ",isSetMemberLinearSearch(arr1,77));

//    printf("is Member = %d ",isSetMemberBinarySearch(arr1,5));

    arr3 = UnionWOTMerge(&arr1,&arr2);

    Display(*arr3);



    return 0;
}
