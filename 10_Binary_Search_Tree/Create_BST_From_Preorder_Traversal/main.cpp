#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;

    Node(int data)
    {
        this->data = data;
        lchild = rchild = NULL;
    }
};

class BST
{
private:
    Node* root;

public:
    BST(){ root = NULL; }
    Node* getRoot(){ return root; }
    void createFromPreorder(int pre[], int szOfarr);
    void Inorder(Node *p);
};

void BST::Inorder(Node *p)
{
    if(p == NULL)
        return;

    Inorder(p->lchild);
    cout<<p->data<<" ";
    Inorder(p->rchild);

}

void BST::createFromPreorder(int pre[], int szOfarr)
{
    int i=0;
    // create New node
    root = new Node(pre[i++]);

    Node *p=root, *t;
    stack<Node*> stk;

    while(i<szOfarr)
    {
        // Left child case
        if(pre[i] < p->data)
        {
            t = new Node(pre[i++]);
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            if((pre[i] > p->data) && (pre[i] < (stk.empty()? 32767:stk.top()->data)) )
            {
                // Right child case
                t = new Node(pre[i++]);
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}



int main()
{
    BST bst;

    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre)/sizeof(pre[0]);

    bst.createFromPreorder(pre, n);

    cout << "BST from Preorder: ";
    bst.Inorder(bst.getRoot());

    cout<<endl;

    return 0;
}
