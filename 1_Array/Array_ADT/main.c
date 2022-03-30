#include <stdio.h>
#include <stdlib.h>


struct Array {

     int A[10];
     int size;
     int length;

};


void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++){
        printf("%d\n",arr.A[i]);
    }
}


void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size){
        arr->A[arr->length] = x;
        arr->length++;
    }
}


void Insert(struct Array *arr, int index, int x)
{
    if(index>=0 && index <= arr->length)
    {
        // shift elements for inserting
        int i;
        for(i=arr->length; i>index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }

        // insert element
        arr->A[index] = x;
        arr->length++;
    }
}


int Delete(struct Array *arr, int index)
{
    if(index>=0 && index <= arr->length)
    {
        // copy element
        int temp = arr->A[index];

        // shift elements
        int i;
        for(i=index; i<arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return temp;
    }

    return -1;
}

int LinearSearch(struct Array arr, int key)
{
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int ImprovedLinearSearch(struct Array *arr, int key)
{
    int i;
    for(i=0; i<arr->length; i++)
    {
        if(key == arr->A[i])
        {
            // Transpositional way - swapping with previous element one by one
//            swap(&arr->A[i], &arr->A[i-1]);
//            return i-1;

            // Move to Front/Head - swapping with current element with 0th element
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, h, mid;
    l = 0;
    h=arr.length-1;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
        {
            return mid;
        }
        else if(key < arr.A[mid])
        {
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return -1;
}

int RecBinarySearch(int A[],int l, int h, int key)
{
    int mid;
    if(l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
        {
            return mid;
        }
        else if(key < A[mid])
        {
            return RecBinarySearch(A,l,mid-1,key);
        }
        else
        {
            return RecBinarySearch(A,mid+1,h,key);
        }
    }
    return -1;
}


int GetElement(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void SetElement(struct Array *arr, int index, int x)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index] = x;
    }
}

int Sum(struct Array arr)
{
    int total=0,i;
    for(i=0;i<arr.length;i++)
    {
        total += arr.A[i];
    }
    return total;
}

int rSum(int a[], int index)
{
    if(index<0)
    {
        return 0;
    }
    else{
        return rSum(a,index-1) + a[index];
    }
}

float Average(struct Array arr)
{
    int i,total=0;
    float avg=0.0;
    for(i=0;i<arr.length;i++)
    {
        total += arr.A[i];
    }
    avg = (float)total/arr.length;
    return avg;
}

int Max(struct Array arr)
{
    int i, maximum = arr.A[0];
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]>maximum)
            {
                maximum = arr.A[i];
            }
    }
    return maximum;
}

int Min(struct Array arr)
{
    int i, mininum = arr.A[0];
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]<mininum)
            {
                mininum = arr.A[i];
            }
    }
    return mininum;
}


void ReverseByTempArray(struct Array *arr)
{
    int tempArray[arr->length];
    int i,j;
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    {
        tempArray[j] = arr->A[i];
    }
    for(i=0;i<arr->length;i++)
    {
        arr->A[i] = tempArray[i];
    }
}


void ReverseBySwapping(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}


void LShift(struct Array *arr)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length] = 0;
}

void RShift(struct Array *arr)
{
    int i;
    for(i=arr->length-1;i>0;i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = 0;
}


void RotateLeft(struct Array *arr)
{
    int i;
    int tmp = arr->A[0];
    for(i=0;i<arr->length;i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = tmp;
}


void RotateRight(struct Array *arr)
{
    int i;
    int tmp = arr->A[arr->length-1];
    for(i=arr->length-1;i>0;i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = tmp;
}


void InsertInSortArr(struct Array *arr, int x)
{
    if(arr->length == arr->size)
    {
        return;
    }

    int i=arr->length-1;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}


int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}


void RearrangePosNegNum(struct Array *arr)
{
    int i,j;
    i = 0;
    j = arr->length-1;

    while(i<j)
    {
        // left index pointer
        // i ignore -ve number , swap +ve number
        while(arr->A[i]<0)
        {
            i++;
        }
        // Right index pointer
        // j ignore +ve number , swap -ve number
        while(arr->A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}



int main()
{
    struct Array arr = {{2,-3,25,10,-15,-7},10,6};

//    Display(arr);

//    Append(&arr,12);

//    Insert(&arr,2,44);

//    printf("\nDeleted element is %d",Delete(&arr,1));

//    printf("\nElement's index is %d",LinearSearch(arr,66));

//    printf("\nElement's index is %d",ImprovedLinearSearch(&arr,66));

//    printf("\nElement's index is %d",BinarySearch(arr,55));

//    printf("\nElement's index is %d",RecBinarySearch(arr.A,0,arr.length-1,77));

//    printf("\nElement is %d",GetElement(arr,2));

//    SetElement(&arr,3,132);

//    printf("\nBy Loop, Sum is %d",Sum(arr));

//    printf("\nBy using Recursion, Sum is %d",rSum(arr.A ,arr.length));

//    printf("\nAverage is %f",Average(arr));

//    printf("\nMaximum Element is %d",Max(arr));

//    printf("\nMinimum Element is %d",Min(arr));

//    ReverseByTempArray(&arr);

//    ReverseBySwapping(&arr);

//    LShift(&arr);

//    RShift(&arr);

//    RotateLeft(&arr);

//    RotateRight(&arr);

//    InsertInSortArr(&arr,15);

//    printf("is Sorted = %d",isSorted(arr));

    RearrangePosNegNum(&arr);


    Display(arr);


    return 0;
}
