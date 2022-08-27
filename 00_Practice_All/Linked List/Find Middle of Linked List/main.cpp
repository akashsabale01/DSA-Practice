#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void pushAtBack(int data);
    void display();
    int getMiddleOfLL();
    Node *getHead() { return head; }
};

void LinkedList::pushAtBack(int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void LinkedList::display()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// 2nd Way
// int LinkedList::getMiddleOfLL()
// {
//     Node *p = head;
//     int count = 0;

//     while (p != NULL)
//     {
//         p = p->next;
//         count++;
//     }

//     int midIdx = (count / 2);

//     p = head;

//     for (int i = 0; i < midIdx; i++)
//         p = p->next;

//     // after loop we are at midIdx, So return it's data
//     return p->data;
// }

// 2nd Way
// int LinkedList::getMiddleOfLL()
// {
//     Node *p = head, *q = head;

//     while (q != NULL)
//     {
//         q = q->next;
//         if (q != NULL)
//             q = q->next;
//         if (q != NULL)
//             p = p->next;
//     }

//     return p->data;
// }

int LinkedList::getMiddleOfLL()
{
    Node *p = head;
    stack<Node *> stk;
    while (p != NULL)
    {
        stk.push(p);
        p = p->next;
    }

    int popCount = stk.size() / 2;
    p = head;
    while (popCount > 0 && stk.size() != 0)
    {
        stk.pop();
        p = p->next;
        popCount--;
    }

    Node *mid = stk.top();

    return mid->data;
}

int main()
{
    LinkedList list;

    list.pushAtBack(11);
    list.pushAtBack(22);
    list.pushAtBack(33);
    list.pushAtBack(44);
    list.pushAtBack(55);

    // list.display();

    int middle = list.getMiddleOfLL();
    cout << middle << endl;

    // list.display();

    return 0;
}