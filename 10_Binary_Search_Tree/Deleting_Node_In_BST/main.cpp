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

    void Inorder(Node* p);

    Node* DeleteNode(Node* p, int key);

    int Height(Node* p);
    Node* InorderPredecessor(Node* p);
    Node* InorderSuccessor(Node* p);

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

// In-order traversal print keys in sorted order
void Bst::Inorder(Node *p)
{
    if(p == NULL)
        return;

    Inorder(p->lchild);
    cout<<p->data<<" ";
    Inorder(p->rchild);
}

int Bst::Height(Node *p)
{
    if(p == NULL)
        return 0;

    int lh = Height(p->lchild);
    int rh = Height(p->rchild);

    return (lh>rh)? lh+1:rh+1;
}

Node* Bst::InorderPredecessor(Node *p)
{
    // Rightmost child of  Left Subtree
    while(p!=NULL && p->rchild!=NULL)
        p = p->rchild;

    return p;
}

Node* Bst::InorderSuccessor(Node *p)
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

    // Iterative insert
//    int arr[] = {50,10,40,20,30};
//    for(int x: arr)
//        bst.InsertNodeIterative(x);

    // Recursive insert
    int arr1[] = { 15, 10, 20, 8, 12, 16, 25 };
    for(int x: arr1)
        bst.InsertNodeRecursive(bst.getRoot(),x);

    /*
        Build tree is
               root
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12  16    25

        Inorder of bst = 8 10 12 15 16 20 25
        The predecessor of node 15 is 12
        The predecessor of node 10 is 8
        The predecessor of node 20 is 16

    */


    bst.DeleteNode(bst.getRoot(),15);

    cout<<"Inorder Tree Traversal of BST :";
    bst.Inorder(bst.getRoot());
    cout<<endl;

    Node* temp = bst.InorderPredecessor(bst.getRoot());
    cout << "Inorder Predecessor: " << temp->data << endl;

    temp = bst.InorderSuccessor(bst.getRoot());
    cout << "Inorder Successor: " << temp->data << endl;


    return 0;
}
