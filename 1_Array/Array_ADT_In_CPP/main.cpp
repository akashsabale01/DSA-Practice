#include <iostream>

using namespace std;

class Array
{
private:
     int *A;
     int size;
     int length;
     void swap(int *x, int *y);

public:
        Array()
        {
            size = 10;
            length = 0;
            A = new int[size];
        }

        Array(int sz)
        {
            size = sz;
            length = 0;
            A = new int[size];
        }

        ~Array()
        {
            delete []A;
        }

        void Display();
        void Append(int x);
        void Insert(int index, int x);
        int Delete(int index);

        int LinearSearch(int key);
        int ImprovedLinearSearch(int key);
        int BinarySearch(int key);

        int GetElement(int index);
        void SetElement(int index, int x);
        int Sum();
        float Average();
        int Max();
        int Min();
        void ReverseByTempArray();
        void ReverseBySwapping();

        void LShift();
        void RShift();
        void RotateLeft();
        void RotateRight();
        void InsertInSortArr(int x);
        int isSorted();
        void RearrangePosNegNum();

        Array* Merge(Array arr2);
        Array* Union(Array arr2);
        Array* Intersection(Array arr2);
        Array* SetDifference(Array arr2);
//        int isSetMemberLinearSearch(int key);
//        int isSetMemberBinarySearch(int key);
//        int isSetMemberLinearSearchForUnion(int key);
        Array* UnionWOTMerge(Array arr2);

};


void Array::Display()
{
    int i;
    cout<<"\nElements are = ";
    for(i=0;i<length;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


void Array::Append(int x)
{
    if(length < size){
        A[length] = x;
        length++;
    }
}


void Array::Insert(int index, int x)
{
    if(index>=0 && index<=length)
    {
        // shift elements for inserting
        int i;
        for(i=length; i>index; i--)
        {
            A[i] = A[i-1];
        }

        // insert element
        A[index] = x;
        length++;
    }
}


int Array::Delete(int index)
{
    if(index>=0 && index <= length)
    {
        // copy element
        int temp = A[index];

        // shift elements
        int i;
        for(i=index; i<length-1; i++)
        {
            A[i] = A[i+1];
        }
        length--;
        return temp;
    }

    return -1;
}


int Array::LinearSearch(int key)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(key == A[i])
        {
            return i;
        }
    }
    return -1;
}


void Array::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int Array::ImprovedLinearSearch(int key)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(key == A[i])
        {
           // Transpositional way - swapping with previous element one by one
           //swap(&A[i], &A[i-1]);
           //return i-1;

            // Move to Front/Head - swapping with current element with 0th element
            swap(&A[i], &A[0]);
            return 0;
        }
    }
    return -1;
}


int Array::BinarySearch(int key)
{
    int l, h, mid;
    l = 0;
    h=length-1;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
        {
            return mid;
        }
        else if(key < A[mid])
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


//int RecBinarySearch(int A[],int l, int h, int key)
//{
//    int mid;
//    if(l<=h)
//    {
//        mid = (l+h)/2;
//        if(key == A[mid])
//        {
//            return mid;
//        }
//        else if(key < A[mid])
//        {
//            return RecBinarySearch(A,l,mid-1,key);
//        }
//        else
//        {
//            return RecBinarySearch(A,mid+1,h,key);
//        }
//    }
//    return -1;
//}


int Array::GetElement(int index)
{
    if(index>=0 && index<length)
    {
        return A[index];
    }
    return -1;
}


void Array::SetElement( int index, int x)
{
    if(index>=0 && index<length)
    {
        A[index] = x;
    }
}


int Array::Sum()
{
    int total=0,i;
    for(i=0;i<length;i++)
    {
        total += A[i];
    }
    return total;
}


//int rSum(int a[], int index)
//{
//    if(index<0)
//    {
//        return 0;
//    }
//    else{
//        return rSum(a,index-1) + a[index];
//    }
//}


float Array::Average()
{
    int i,total=0;
    float avg=0.0;
    for(i=0;i<length;i++)
    {
        total += A[i];
    }
    avg = (float)total/length;
    return avg;
}


int Array::Max()
{
    int i, maximum = A[0];
    for(i=1;i<length;i++)
    {
        if(A[i]>maximum)
            maximum = A[i];
    }
    return maximum;
}


int Array::Min()
{
    int i, mininum = A[0];
    for(i=1;i<length;i++)
    {
        if(A[i]<mininum)
            {
                mininum = A[i];
            }
    }
    return mininum;
}


void Array::ReverseByTempArray()
{
    int tempArray[length];
    int i,j;
    for(i=length-1,j=0;i>=0;i--,j++)
    {
        tempArray[j] = A[i];
    }
    for(i=0;i<length;i++)
    {
        A[i] = tempArray[i];
    }
}


void Array::ReverseBySwapping()
{
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--)
    {
        swap(&A[i],&A[j]);
    }
}


void Array::LShift()
{
    int i;
    for(i=0;i<length;i++)
    {
        A[i] = A[i+1];
    }
    A[length] = 0;
}


void Array::RShift()
{
    int i;
    for(i=length-1;i>0;i--)
    {
        A[i] = A[i-1];
    }
    A[0] = 0;
}


void Array::RotateLeft()
{
    int i;
    int tmp = A[0];
    for(i=0;i<length;i++)
    {
        A[i] = A[i+1];
    }
    A[length-1] = tmp;
}


void Array::RotateRight()
{
    int i;
    int tmp = A[length-1];
    for(i=length-1;i>0;i--)
    {
        A[i] = A[i-1];
    }
    A[0] = tmp;
}


void Array::InsertInSortArr( int x)
{
    if(length == size)
    {
        return;
    }

    int i=length-1;
    while(i>=0 && A[i]>x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}


int Array::isSorted()
{
    int i;
    for(i=0;i<length-1;i++)
    {
        if(A[i]>A[i+1])
        {
            return 0;
        }
    }
    return 1;
}


void Array::RearrangePosNegNum()
{
    int i,j;
    i = 0;
    j = length-1;

    while(i<j)
    {
        // left index pointer
        // i ignore -ve number , swap +ve number
        while(A[i]<0)
        {
            i++;
        }
        // Right index pointer
        // j ignore +ve number , swap -ve number
        while(A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(&A[i],&A[j]);
        }
    }
}


// you have to create 2 arrays and store the element. Merge is a binary operation.
// you should write a different program, providing all merge and set operations.

Array* Array::Merge(Array arr2)
{
    int i,j,k;
    i=0,j=0,k=0;

    //struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    Array *arr3 = new Array(length + arr2.length);

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k] = A[i];
            i++,k++;
        }
        else
        {
           arr3->A[k] = arr2.A[j];
           j++,k++;
        }
    }

    for(;i<length;i++)
    {
        arr3->A[k] = A[i];
        k++;
    }

    for(;j<arr2.length;j++)
    {
        arr3->A[k] = arr2.A[j];
        k++;
    }

    arr3->length = length + arr2.length;

    return arr3;
}


Array* Array::Union(Array arr2)
{
    int i,j,k;
    i=0,j=0,k=0;

//    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    Array *arr3 = new Array(length+ arr2.length);

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k] = A[i];
            i++,k++;
        }
        else if(arr2.A[j]<A[i])
        {
           arr3->A[k] = arr2.A[j];
           j++,k++;
        }
        else if(A[i] == arr2.A[j])
        {
            // both equal then copy only 1 value & increment i,j,k
            arr3->A[k] = A[i];
            i++,j++,k++;
        }
    }

    for(;i<length;i++)
    {
        arr3->A[k] = A[i];
        k++;
    }

    for(;j<arr2.length;j++)
    {
        arr3->A[k] = arr2.A[j];
        k++;
    }

    arr3->length = k;

    return arr3;
}


Array* Array::Intersection(Array arr2)
{
    int i,j,k;
    i=0,j=0,k=0;

//    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    Array *arr3 = new Array(length + arr2.length);

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            i++;
        }
        else if(arr2.A[j]<A[i])
        {
            j++;
        }
        else if(A[i] == arr2.A[j])
        {
            // both equal then copy only 1 value & increment i,j,k
            arr3->A[k] = A[i];
            i++,j++,k++;
        }
    }

    arr3->length = k;

    return arr3;
}


Array* Array::SetDifference(Array arr2)
{
    int i,j,k;
    i=0,j=0,k=0;

//    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    Array *arr3 = new Array(length + arr2.length);

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k] = A[i];
            i++,k++;
        }
        else if(arr2.A[j]<A[i])
        {
           j++;
        }
        else if(A[i] == arr2.A[j])
        {
            // both equal then ignore
            i++,j++;
        }
    }

    for(;i<length;i++)
    {
        arr3->A[k] = A[i];
        k++;
    }

    arr3->length = k;

    return arr3;
}


//int Array::isSetMemberLinearSearch(int key)
//{
//    int i;
//    for(i=0;i<length;i++)
//    {
//        if(key == A[i])
//        {
//            return 1;
//        }
//    }
//
//    return 0;
//}
//

//int Array::isSetMemberBinarySearch(int key)
//{
//    int l,mid,h;
//    l=0;
//    h=length;
//
//    while(l<=h)
//    {
//        mid = (l+h)/2;
//        if(key == A[mid])
//            return 1;
//        else if(key<A[mid])
//            h=mid-1;
//        else if(key>A[mid])
//            l=mid+1;
//    }
//
//    return 0;
//}
//
//int Array::isSetMemberLinearSearchForUnion(int key)
//{
//    int i;
//    for(i=0;i<length;i++)
//    {
//        if(key == A[i])
//        {
//            return 1;
//        }
//    }
//
//    return 0;
//}


Array* Array::UnionWOTMerge(Array arr2)
{
    int i,j,k;
    k=0;

//    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    Array *arr3 = new Array(length+arr2.length);

    arr3->length = length + arr2.length;

    for(i=0;i<length;i++)
    {
        arr3->A[k] = A[i];
        k++;
    }

    for(j=0;j<arr2.length;)
    {
        if(arr3->BinarySearch(arr2.A[j]) != 1 )
        {
            arr3->A[k] = arr2.A[j];
            j++,k++;
        }
        else
        {
            j++;
        }
    }

    return arr3;
};


int main()
{
//    struct Array arr = {{2,-3,25,10,-15,-7},10,6};

//    Display(arr);

//    Append(&arr,12);

//    Insert(&arr,2,44);

//    cout<<"\nDeleted element is %d",Delete(&arr,1));

//    cout<<"\nElement's index is %d",LinearSearch(arr,66));

//    cout<<"\nElement's index is %d",ImprovedLinearSearch(&arr,66));

//    cout<<"\nElement's index is %d",BinarySearch(arr,55));

//    cout<<"\nElement's index is %d",RecBinarySearch(arr.A,0,arr.length-1,77));

//    cout<<"\nElement is %d",GetElement(arr,2));

//    SetElement(&arr,3,132);

//    cout<<"\nBy Loop, Sum is %d",Sum(arr));

//    cout<<"\nBy using Recursion, Sum is %d",rSum(arr.A ,arr.length));

//    cout<<"\nAverage is %f",Average(arr));

//    cout<<"\nMaximum Element is %d",Max(arr));

//    cout<<"\nMinimum Element is %d",Min(arr));

//    ReverseByTempArray(&arr);

//    ReverseBySwapping(&arr);

//    LShift(&arr);

//    RShift(&arr);

//    RotateLeft(&arr);

//    RotateRight(&arr);

//    InsertInSortArr(&arr,15);

//    cout<<"is Sorted = %d",isSorted(arr));

//    RearrangePosNegNum(&arr);

//    Display(arr);

//    struct Array arr1 = {{2,5,8,10,12},10,5};
//    struct Array arr2 = {{1,5,6,10,19},10,5};
//    struct Array *arr3;

//    arr3 = Merge(&arr1,&arr2);

//    arr3 = Union(&arr1,&arr2);

//    arr3 = Intersection(&arr1,&arr2);

//    arr3 = SetDifference(&arr1,&arr2);

//    cout<<"is Member = %d ",isSetMemberLinearSearch(arr1,77));

//    cout<<"is Member = %d ",isSetMemberBinarySearch(arr1,5));

//    arr3 = UnionWOTMerge(&arr1,&arr2);

//    Display(*arr3);

//     *****************Menu Driven Program*********************

    Array *arr1;

    int ch,sz;
    int x, index;

    cout<<"Enter Size of Array = ";
    cin>>sz;

    //create array in heap
//    arr.A = (int *)malloc(arr.size*sizeof(int));

//    arr1.A = new int[size];
    arr1 = new Array(sz);

    do
    {
         cout<<"\nMenu\n";
         cout<<"1. Insert\n";
         cout<<"2. Append\n";
         cout<<"3. Delete\n";
         cout<<"4. Display\n";
         cout<<"5. Search\n";
         cout<<"6. Sum\n";
         cout<<"7. Average\n";
         cout<<"8. Max\n";
         cout<<"9. Min\n";
         cout<<"10. Reverse Array\n";
         cout<<"11. LShift\n";
         cout<<"12. RotateLeft\n";
         cout<<"13. isSorted\n";
         cout<<"14. RearrangePosNegNum\n";
         cout<<"15. Exit\n";

        cout<<"enter you choice ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"Enter an element and index";
            cin>>x>>index;
            arr1->Insert(index,x);
            break;

        case 2:
            cout<<"Enter an element = ";
            cin>>x;
            arr1->Append(x);
            break;

        case 3:
            cout<<"Enter index = ";
             cin>>index;
             x= arr1->Delete(index);
             cout<<"Deleted Element is "<<x<<endl;
             break;

        case 4:
            arr1->Display();
            break;

        case 5:
            cout<<"Enter element to search ";
            cin>>x;
            index=arr1->LinearSearch(x);
            cout<<"Element's index = "<<index;
            break;

        case 6:
            cout<<"Sum = "<<arr1->Sum()<<endl;;
            break;

        case 7:
            cout<<"Average = "<<arr1->Average()<<endl;;
            break;

        case 8:
            cout<<"Max = "<<arr1->Max()<<endl;;
            break;

        case 9:
            cout<<"Min = "<<arr1->Min()<<endl;;
            break;

        case 10:
            arr1->ReverseByTempArray();
            break;

        case 11:
            arr1->LShift();
            break;

        case 12:
            arr1->RotateLeft();
            break;

        case 13:
            cout<<"is Sorted = "<<arr1->isSorted()<<endl;
            break;

        case 14:
            arr1->RearrangePosNegNum();
            break;

        }

    }while(ch<15);

    return 0;
}
