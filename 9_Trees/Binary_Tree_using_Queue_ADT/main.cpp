#include <iostream>
#include "Queue.h"

using namespace std;

class Tree
{
private:
    Node* root;

public:

    Tree(){root=NULL;}

    void CreateTree();

    void Preorder() { Preorder(root); };
    void Preorder(Node *p);

    void Inorder() { Inorder(root); };
    void Inorder(Node *p);

    void Postorder() { Postorder(root); };
    void Postorder(Node *p);

    void Levelorder() { Levelorder(root); };
    void Levelorder(Node *p);

    int Height() { return Height(root); };
    int Height(Node *p);
};

void Tree::CreateTree()
{
    Node *p,*t;
    int value;

    Queue q(100);

    cout<<"Enter Root Value = ";
    cin>>value;
    root = new Node;
    root->data =  value;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout<<"Enter left child of "<<p->data<<" = ";
        cin>>value;
        if(value != -1)
        {
            t = new Node;
            t->data = value;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        cout<<"Enter Right child of "<<p->data<<" = ";
        cin>>value;
        if(value != -1)
        {
            t = new Node;
            t->data = value;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if(p != NULL)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if(p != NULL)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if(p != NULL)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree::Levelorder(Node *p)
{
    Queue q(100);

    cout<<root->data<<" ";
    q.enqueue(root);

    while(!q.isEmpty())
    {
        root = q.dequeue();

        if(root->lchild){
            cout<<root->lchild->data<<" ";
            q.enqueue(root->lchild);
        }

        if(root->rchild){
            cout<<root->rchild->data<<" ";
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Height(Node *p)
{
    int x=0,y=0;
    if(p==0) return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);

    return (x>y)? x+1:y+1;
}


int main()
{
    Tree t;
    t.CreateTree();

    cout<<endl<<"Preorder Traversal: ";
    t.Preorder();

    cout<<endl<<"Inorder Traversal: ";
    t.Inorder();

    cout<<endl<<"Postorder Traversal: ";
    t.Postorder();

    cout<<endl<<"Levelorder Traversal: ";
    t.Levelorder();

    cout<<endl<<"Height of Tree : "<<t.Height();

    cout<<endl;

    return 0;
}
