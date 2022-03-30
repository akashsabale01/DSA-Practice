#include <iostream>

using namespace std;

//create Node
class Node
{
public:
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// Create Linked list
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void Push_front(int data);
    void Push_back(int data);
    void Display();
    void Insert(int data, int position);
    bool Search(int key);


};

void List::Push_front(int data)
{
    // Empty linked list
    if(head==NULL)
    {
        //create new node n by using constructor Node() in Node class
        Node *n = new Node(data);
        head = tail = n;
        return;
    }
    // linked list is already created
    else
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
    }
    //Note- here n is local variable, So it will be destroyed after function ends
}

 void List::Push_back(int data)
{
    Node *n = new Node(data);
    if(head==NULL)
    {
        head = tail = n;
        return;
    }
    else
    {
        tail->next = n;
        tail = n;
    }
}

void List::Display()
{
    Node *p = head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void List::Insert(int data, int position)
{
    if(position==0)
    {
        Push_front(data);
    }
    else
    {
        Node *temp = head;
        for(int jump=0;jump<position-1;jump++)
        {
            temp = temp->next;
        }

        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

}

bool List::Search(int key)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        if(temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}


int main()
{
    List l;

    l.Push_front(2);
    l.Push_front(1);

    l.Push_back(4);
    l.Push_back(5);

    l.Insert(7,3);
    l.Insert(10,0);

     l.Display();

    int k = 4;

    if(l.Search(k))
        cout<<k<<" found"<<endl;
    else
        cout<<k<<" Not found"<<endl;

    return 0;
}
