#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;

    Node(int data)
    {
        this->data = data;
        lchild = rchild = NULL;
    }
};

class Bst
{
private:
    Node *root;

public:
    Bst(){ root = NULL; }
    Node* getRoot() { return root; }

    void InsertNodeIterative(int key);
    Node* InsertNodeRecursive(Node* p, int key);

    Node* SearchIterative(int key);
    Node* SearchRecursive(Node *p, int key);
    bool SearchBool(Node *p, int key);

    void Inorder(Node* p);

    Node* DeleteNode(Node* p, int key);

};

void Bst::InsertNodeIterative(int key)
{
    // p pointer points to root
    // q is tail pointer, q follows to p, q acts as previous node of p
    // t is pointer for creating new node

    Node *p = root, *q = NULL, *t;

    if(p == NULL)
    {
        t = new Node(key);
        root = t;
        return;
    }

    // Search if key is Present or Not
    while(p != NULL)
    {
        q = p; // q follows p
        if(key == p->data)
            return;
        else if(key < p->data)
            p = p->lchild ;
        else
            p = p->rchild;
    }

    // After loop p will became NULL and q will points to location where we have to insert
    t = new Node(key);

    if(key < q->data)
        q->lchild = t;
    else
        q->rchild = t;
}

Node* Bst::InsertNodeRecursive(Node* p, int key)
{
    if(p == NULL)
    {
        Node *t = new Node(key);
        if(root==NULL)
            root = t;
        return t;
    }

    if(key < p->data)
        p->lchild = InsertNodeRecursive(p->lchild, key);
    else if(key > p->data)
        p->rchild = InsertNodeRecursive(p->rchild, key);

    return p;
}

Node* Bst::SearchIterative(int key)
{
    Node *p = root;

    // root is NULL
    if(p == NULL)
        return NULL;

    while(p != NULL)
    {
        if(key == p->data)
            return p;
        else if(key < p->data)
            p = p->lchild ;
        else
            p = p->rchild;
    }

     return NULL;  // Not found
}

Node* Bst::SearchRecursive(Node *p, int key)
{
    if(p == NULL)
        return NULL;

    if(key == p->data)
        return p;
    else if(key < p->data)
        return SearchRecursive(p->lchild, key);
    else
        return SearchRecursive(p->rchild, key);
}

bool Bst::SearchBool(Node *p, int key)
{
    if(p == NULL)
        return false;

    if(key == p->data)
        return true;

    else if(key < p->data)
        return SearchBool(p->lchild, key);

    else
        return SearchBool(p->rchild, key);
}

// In-order traversal print keys in sorted order
void Bst::Inorder(Node *p)
{
    if(p == NULL)
        return;

    Inorder(p->lchild);
    cout<<p->data<<" ";
    Inorder(p->rchild);
}


int Height(Node *p)
{
    if(p == NULL)
        return 0;

    int lh = Height(p->lchild);
    int rh = Height(p->rchild);

    return (lh>rh)? lh+1:rh+1;
}


Node* InorderPredecessor(Node *p)
{
    // Rightmost child of  Left Subtree
    while(p!=NULL && p->rchild!=NULL)
        p = p->rchild;

    return p;
}

Node* InorderSuccessor(Node *p)
{
    // Leftmost child of Right Subtree
    while(p!=NULL && p->lchild!=NULL)
        p = p->lchild;

    return p;
}

Node* Bst::DeleteNode(Node* p, int key)
{
    Node *q;

    // Delete Node
    if(p == NULL)
        return NULL;

    // if it is Leaf Node
    if(p->lchild==NULL && p->rchild==NULL && p->data==key)
    {
        // if only one Node present in bst
        if(p == root)
            root = NULL;
        delete p;
        return NULL;
    }

    // Search for Key
    if(key < p->data)
        p->lchild = DeleteNode(p->lchild, key);
    else if(key > p->data)
        p->rchild = DeleteNode(p->rchild, key);
    else
    {
        // Based on Height of Subtree, we decide whether we want to delete from Left side or Right side

        //Left side is Have greater Height
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = InorderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = DeleteNode(p->lchild, q->data); // Delete q
        }
        else
        {
            q = InorderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = DeleteNode(p->rchild, q->data); // Delete q
        }
    }

    return p;
}


int main()
{
    Bst bst;
//
//    // Iterative insert
//    int arr[] = {10,5,20,8,30};
//    for(int x: arr)
//        bst.InsertNodeIterative(x);
//
//    cout<<"Inorder Tree Traversal of BST :";
//    bst.Inorder(bst.getRoot());
//    cout<<endl;
//
//    // Iterative search
//    int k = 10;
//    Node *temp = bst.SearchIterative(k);
//    if(temp!=NULL)
//        cout<<"Key "<<temp->data<<" Found"<<endl;
//    else
//        cout<<"Key "<<k<<" Not Found"<<endl;
//

//
//    // Recursive search
//    k = 1;
//    temp = bst.SearchRecursive(bst.getRoot(),1);
//    if(temp!=NULL)
//        cout<<"Key "<<temp->data<<" Found"<<endl;
//    else
//        cout<<"Key "<<k<<" Not Found"<<endl;
//
//    // Search with bool result
//    k = 56;
//    bool isPresent = bst.SearchBool(bst.getRoot(),56);
//    if(isPresent)
//        cout<<"Key Found"<<endl;
//    else
//        cout<<"Key "<<k<<" Not Found"<<endl;

    // Recursive insert
    bst.InsertNodeRecursive(bst.getRoot(),50);
    bst.InsertNodeRecursive(bst.getRoot(),29);
//    bst.InsertNodeRecursive(bst.getRoot(),29); // repeated
    bst.InsertNodeRecursive(bst.getRoot(),70);
    bst.InsertNodeRecursive(bst.getRoot(),1);
    bst.InsertNodeRecursive(bst.getRoot(),64);

    bst.DeleteNode(bst.getRoot(),1);

    cout<<"Inorder Tree Traversal of BST :";
    bst.Inorder(bst.getRoot());
    cout<<endl;


    return 0;
}
