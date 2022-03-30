#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Tree
{
private:
    Node* root;

public:

    Tree(){root=NULL;}

    void CreateTree();

    // Passing Private Parameter in Constructor
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

    void PreorderIterative(){PreorderIterative(root);};
    void PreorderIterative(Node *p);

    void InorderIterative(){InorderIterative(root);};
    void InorderIterative(Node *p);

    void PostorderIterative(){PostorderIterative(root);};
    void PostorderIterative(Node *p);
};

void Tree::CreateTree()
{
    Node *p,*t;
    int value;

    queue<Node*> q;

    cout<<"Enter Root Value = ";
    cin>>value;
    root = new Node;
    root->data =  value;
    root->lchild = root->rchild = NULL;
    q.push(root);

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        cout<<"Enter left child of "<<p->data<<" = ";
        cin>>value;
        if(value != -1)
        {
            t = new Node;
            t->data = value;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }

        cout<<"Enter Right child of "<<p->data<<" = ";
        cin>>value;
        if(value != -1)
        {
            t = new Node;
            t->data = value;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
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
    queue<Node*> q;

    cout<<root->data<<" ";
    q.push(root);

    while(!q.empty())
    {
        root = q.front();
        q.pop();

        if(root->lchild){
            cout<<root->lchild->data<<" ";
            q.push(root->lchild);
        }

        if(root->rchild){
            cout<<root->rchild->data<<" ";
            q.push(root->rchild);
        }
    }
}

int Tree::Height(Node *p)
{
    if(p==0) return 0;
    int x=0,y=0;
    x = Height(p->lchild);
    y = Height(p->rchild);

    return (x>y)? x+1:y+1;
}

void Tree::PreorderIterative(Node *p)
{
    stack<Node*> stk;

    while(p!=NULL || !stk.empty())
    {
        if(p!=NULL)
        {
            cout<<p->data<<" ";
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }

}

void Tree::InorderIterative(Node *p)
{
    stack<Node*> stk;

    while(p!=NULL || !stk.empty())
    {
        if(p!=NULL)
        {
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout<<p->data<<" ";
            p = p->rchild;
        }
    }

}

void Tree::PostorderIterative(Node *p)
{
    stack<long int> stk;
    long int temp;

    while(p!=NULL || !stk.empty())
    {
        if(p!=NULL)
        {
            stk.push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = stk.top();
            stk.pop();
            if(temp>0)
            {
                stk.push(-temp);
                p = ((Node*)temp)->rchild;
            }
            else
            {
                cout<<((Node*)(-temp))->data<<" ";
                p = NULL;
            }
        }
    }

}

int main()
{
    Tree t;
    t.CreateTree();

//    cout<<endl<<"Preorder Traversal: ";
//    t.Preorder();
//
//    cout<<endl<<"Inorder Traversal: ";
//    t.Inorder();
//
//    cout<<endl<<"Postorder Traversal: ";
//    t.Postorder();
//
//    cout<<endl<<"Levelorder Traversal: ";
//    t.Levelorder();
//
//    cout<<endl<<"Height of Tree : "<<t.Height();

//    cout<<endl<<"Iterative Preorder Traversal: ";
//    t.PreorderIterative();
//
//    cout<<endl<<"Iterative Inorder Traversal: ";
//    t.InorderIterative();

    cout<<endl<<"Iterative Inorder Traversal: ";
    t.PostorderIterative();

    cout<<endl;

    return 0;
}
