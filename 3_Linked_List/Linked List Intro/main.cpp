#include <iostream>

using namespace std;

// In Class, Default Access Specifier is Private
// In Struct, Default Access Specifier is Public

// Create Node
class Node
{
public:
    int data;
    Node *next;
};

// Below, We have declare a global head pointer or first pointer,
// which will store the address of very first node.
// also tail pointer which will be useful in insert at last position of linked list
Node *head = NULL;
Node *tail = NULL; // this tail pointer is for InsetAtLast() function
Node *second = NULL;
Node *third = NULL;


void create(int A[], int n)
{
    // Creating 1st node
    head = new Node;
    head->data = A[0];
    head->next = NULL;

    //  we create a last Node which help us to
    Node *temp, *last;
    last = head;

    // Creating remaining nodes
    for(int i=1;i<n;i++)
    {
        // Create a temporary Node
        temp = new Node;

        // Fill temporary Node
        temp->data = A[i];
        temp->next = NULL;

        // last's next is pointing to temp
        last->next = temp;
        last = temp;
    }
}

void create2ndLL(int A[], int n)
{
    // Creating 1st node
    second = new Node;
    second->data = A[0];
    second->next = NULL;

    //  we create a last Node which help us to
    Node *temp, *last;
    last = second;

    // Creating remaining nodes
    for(int i=1;i<n;i++)
    {
        // Create a temporary Node
        temp = new Node;

        // Fill temporary Node
        temp->data = A[i];
        temp->next = NULL;

        // last's next is pointing to temp
        last->next = temp;
        last = temp;
    }
}

void Display(Node *p)
{
    while(p!=NULL)
    {
        cout<< p->data <<" ";
        // Move pointer p to next node
        p = p->next;
    }
    cout<<endl;
}

void RDisplay1(Node *p)
{
    // Head Recursion - print at calling phase
    // print in same order
    if(p!=NULL)
    {
        cout<< p->data <<" ";
        //passing next node pointer
        RDisplay1(p->next);
    }
}

void RDisplay2(Node *p)
{
    // Tail Recursion - print at Returning phase
    // print in Reverse order
    if(p!=NULL)
    {
        //passing next node pointer
        RDisplay2(p->next);

        cout<< p->data <<" ";

    }
}

int Count(Node *p)
{
    int cnt=0;
    while(p!=NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

int CountR(Node *p)
{
    if(p==NULL)
        return 0;
    else
    {
//        return CountR(p->next)+1;
        return 1+CountR(p->next);
    }
}

int Add(Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int AddR(Node *p)
{
    if(p==NULL)
        return 0;
    else
        return AddR(p->next) + p->data;
}

int Max(Node *p)
{
// you can also set max value as INT_MIN , So that it can work for negative numbers also
// int m = INT_MIN;
    int m = p->data; // storing 1st element as max element
    while(p!=NULL)
    {
        if(p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;

}

int MaxR(Node *p)
{
    int x = 0;

    if(p==NULL)
        return INT_MIN;

    x = MaxR(p->next);
    if(x > p->data)
        return x;
    else
        return p->data;
}

int Min(Node *p)
{
// you can also set max value as INT_MAX , So that it can work for negative numbers also
//    int m = p->data; // storing 1st element as max element
    int m = INT_MAX;
    while(p!=NULL)
    {
        if(p->data < m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int MinR(Node *p)
{
    int x = 0;
    if(p==NULL)
        return INT_MAX;
    x = MinR(p->next);
    if(x < p->data)
        return x;
    else
        return p->data;
}

Node* LSearch(Node *p, int key)
{
    while(p!=NULL)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

Node* LSearchR(Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(key== p->data)
        return p;
    return LSearchR(p->next, key);
}

Node* ImprovedLSearch(Node *p, int key)
{
    Node *q = NULL;
    while(p!=NULL)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;

    }
    return NULL;
}

void Insert(Node *p, int position, int dt)
{
    if(position<0 || position>Count(p))
        return;

    // position is valid
    Node *t = new Node;
    t->data = dt;

    // Insert in Front
    if(position == 0)
    {
        t->next = head;
        head = t;
    }
    // Insert in other position than Front like 1,2,3 or last
    else if(position>0)
    {
        // move pointer p to that position
        for(int i=0;(i<position-1&&p);i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void InsertAtLast(int dt)
{
    Node *t = new Node;
    t->data = dt;
    t->next = NULL;
    if(head == NULL)
    {
        head = tail = t;
    }
    else
    {
        tail->next = t;
        tail = t;
    }
}

void InsertInSortedLL(Node *p, int dt)
{
    Node *q = NULL;
    Node *t = new Node;
    t->data = dt;
    t->next = NULL;

    // Check if Linked list is empty or not
    if(head == NULL)
    {
        head = t;
    }
    else
    {
        while(p && p->data<dt)
        {
            q = p;
            p = p->next;
        }
        // check if it is 1st node
        if(p == head)
        {
            t->next = p;
            head = t;
        }
        // otherwise it it other node than 1st node
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(Node *p, int position)
{
    Node *q = NULL;
    int x = -1;

    if(position<1 || position>Count(p))
        return -1;

    // case 1 - delete 1st node
    if(position == 1)
    {
        x = p->data;
        head = head->next;
        delete p;
        return x;
    }

    // case 2 - delete other than 1st node
    else
    {
        for(int i=0;i<position-1;i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

bool isSortedLL(Node *p)
{
    int x = INT_MIN;
    while(p!=NULL)
    {
        if(p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

void RemoveDuplicatesFromSortedLL(Node *p)
{
    Node *q = p->next;
    while(q != NULL)
    {
        // check if both nodes have different data
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        // otherwise both nodes have Same data
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void ReverseLLUsingTempArray(Node *p)
{
    int A[Count(p)] = {0};
//    int *A = new int[Count(p)]; // array in heap

    int i=0;
    //copy elements from Linked list to array
    while(p!=NULL)
    {
        A[i] = p->data;
        i++;
        p = p->next;
    }
    //copy elements from array to Linked list
    p = head;
    i--;
    while(p!=NULL)
    {
        p->data = A[i];
        i--;
        p = p->next;
    }
}

void ReverseLLUsing3SlidingPointer(Node *p)
{
    Node *q = NULL;
    Node *r = NULL;
    while(p != NULL)
    {
        // slide pointers
        r = q;
        q = p;
        p = p->next;
        // change link of q
        q->next = r;
    }
    head = q;
}

void ReverseLLUsingRecursion(Node *q, Node *p)
{
    if(p!=NULL)
    {
        ReverseLLUsingRecursion(p,p->next);
        p->next = q; // change link in returning phase
    }
    else
    {
        //when p is NULL, q will be its previous node i.e. tail node
        head = q;
    }

}

void Concat(Node *p, Node *q)
{
    third = p; // third points to 1st LL
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void MergeLL(Node *p, Node *q)
{
    Node *last = NULL;
    // move third and last to LL having 1st element smaller than other LL
    if(p->data < q->data)
    {
        // Move third and last to 1st node of 1st LL
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        // Move third and last to 1st node of 2nd LL
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    // repeat process of creating links of third LL to that element which is small
    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    // check for remaining nodes
    if(p!=NULL)
    {
        last->next = p;
    }
    else
    {
        last->next = q;
    }
}

bool isLoop(Node *f)
{
    Node *p,*q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;

        if(q!=NULL)
            q = q->next;
        else
            q = q;
    }while((p!=NULL && q!=NULL) && p!=q);

//    (p!=NULL && q!=NULL) this Condition becomes false for LL containing No Loop
//    p!=q ---- this Condition becomes false for LL containing Loop
    if(p==q)
        return true;
    else
        return false;
}



int main()
{
//    int A[] = {5,6,2,4,8};
//    int n = sizeof(A)/sizeof(A[0]);
//
//    create(A,n);

//    Display(head)
//    RDisplay1(head);
//    RDisplay2(head);

//    cout<<"Count of Nodes = "<<Count(head)<<endl;
//    cout<<"Count of Nodes = "<<CountR(head)<<endl;

//    cout<<"Sum = "<<Add(head)<<endl;
//    cout<<"Sum = "<<AddR(head)<<endl;

//    cout<<"Max = "<<Max(head)<<endl;
//    cout<<"Max = "<<MaxR(head)<<endl;

//    cout<<"Min = "<<Min(head)<<endl;
//    cout<<"Min = "<<MinR(head)<<endl;

//    int key = -1;
//    if(LSearch(head,key))
//        cout<<key<<" is found"<<endl;
//    else
//        cout<<key<<" is Not found"<<endl;
//    Display(head);

//    if(ImprovedLSearch(head,key))
//        cout<<key<<" is found"<<endl;
//    else
//        cout<<key<<" is Not found"<<endl;

//    Creating Linked List using Insert()
//    Insert(head,0,12); // only index 0 is valid
//    Insert(head,1,23); // index 0,1 valid
//    Insert(head,2,32); // index 0,1,2 valid
//    Insert(head,3,43); // index 0,1,2,3 valid
//
//    Display(head);
//    cout<<endl;

//    Performing operations on Already created linked list
//    Insert(head,0,7); // before 1st node
//    Insert(head,1,5); // in last
//    Insert(head,3,4); // in between nodes
//    Insert(head,13,8); // Not valid index

// Creating linked list using InsertAtLast() function
//    InsertAtLast(22);
//    InsertAtLast(44);
//    InsertAtLast(77);
//    InsertAtLast(33);
//    InsertAtLast(55);

//    Display(head);
//    cout<<endl;
////    InsertInSortedLL(head,996);
//
//    cout<<"Deleted element is "<<Delete(head,0)<<endl;

//    Display(head);

//    if(isSortedLL(head))
//    {
//        cout<<"Linked list is Sorted"<<endl;
//    }
//    else
//    {
//        cout<<"Linked list is NOT Sorted"<<endl;
//    }

//    RemoveDuplicatesFromSortedLL(head);

//    ReverseLLUsingTempArray(head);
//    ReverseLLUsing3SlidingPointer(head);
//    ReverseLLUsingRecursion(NULL,head);
//    Display(head);

// *** Merging & Concatenate operation of two LL *********
//    int Arr1[] = {910,920,930,940,950};
//    int n1 = sizeof(Arr1)/sizeof(Arr1[0]);
//
//    int Arr2[] = {51,151,251,351,451};
//    int n2 = sizeof(Arr2)/sizeof(Arr2[0]);
//
//    create(Arr1,n1);
//    create2ndLL(Arr2,n2);

//    cout<<"First LL = ";
//    Display(head);
//
//    cout<<"Second LL = ";
//    Display(second);

//    Concat(head,second);
//    cout<<"After Concatenation of two LL"<<endl;
//
//    MergeLL(head,second);
//    cout<<"Third LL = ";
//    Display(third);

// ******* Check LOOP in LL *****8
    int Arr[] = {5,6,2,4,8};
    int n = sizeof(Arr)/sizeof(Arr[0]);
    create(Arr,n);

//    Node *t1=head,*t2=head;
//    t1 = t1->next->next; // element 2
//    t2 = t2->next->next->next->next; // element 8
//    t2->next = t1; // creating loop from 8 to 2

    if(isLoop(head))
    {
        cout<<"LL contain Loop";
    }
    else
    {
        cout<<"LL Not contain Loop";
    }








    return 0;
}
