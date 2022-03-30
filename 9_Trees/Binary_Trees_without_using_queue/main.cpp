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

using namespace std;

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

void Preorder(Node* root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    Preorder(root->lchild);
    Preorder(root->rchild);
// TC = O(n) for visiting all nodes
// SC = O(N) max space will be taken when it is skewed Tree i.e. n spaces
}


void Inorder(Node* root)
{
    if(root==NULL)
        return ;
    Inorder(root->lchild);
    cout<<root->data<<" ";
    Inorder(root->rchild);
}


void Postorder(Node* root)
{
    if(root==NULL)
        return ;
    Postorder(root->lchild);
    Postorder(root->rchild);
    cout<<root->data<<" ";
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

    cout<<"Preorder Tree Traversal: ";
    Preorder(root);
    cout<<endl;

    cout<<"Inorder Tree Traversal: ";
    Inorder(root);
    cout<<endl;

    cout<<"Postorder Tree Traversal: ";
    Postorder(root);
    cout<<endl;



    return 0;
}

