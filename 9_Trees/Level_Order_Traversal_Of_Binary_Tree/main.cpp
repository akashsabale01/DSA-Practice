/*
Given tree is
       1
    2     3
   4 5   6 7

*** DFS Traversal ways ***
Pre Order (d l r) = 1 2 4 5 3 6 7 --- pre means data is at first position
In order (l d r) = 4 2 5 1 6 3 7  --- in means data is at middle position
Post Order (l r d) = 4 5 2 6 7 3 1  --- in means data is at last position

*** BFS Traversal ways ***
BFS also called as Level order
Level order(BFS) = 1 2 3 4 5 6 7

*/

#include <iostream>
#include <queue>

using namespace std;

// Create node for tree
class Node
{
public:
    Node *lchild, *rchild;
    int data;

    Node(int data)
    {
        this->data = data;
        lchild = rchild = NULL;
    }
};

void LevelOrder(Node *p)
{
    queue<Node*> q;

    cout<< p->data <<" ";
    q.push(p);

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->lchild != NULL)
        {
            cout<< p->lchild->data <<" ";
            q.push(p->lchild);
        }
        if(p->rchild != NULL)
        {
            cout<< p->rchild->data <<" ";
            q.push(p->rchild);
        }
    }
}


int main()
{
    Node *root = new Node(1);
    root->lchild = new Node(2);
    root->rchild = new Node(3);

    root->lchild->lchild = new Node(4);
    root->lchild->rchild = new Node(5);

    root->rchild->lchild = new Node(6);
    root->rchild->rchild = new Node(7);


    cout<<"Level order Tree Traversal: ";
    LevelOrder(root);
    cout<<endl;

    return 0;
}
