#include <iostream>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    int height; // height for calculating Balance Factor
    Node *rchild;

    Node(int data)
    {
        this->data = data;
        lchild = rchild = NULL;
    }
};


class AVL
{
private:
    Node *root;

public:
    AVL(){ root = NULL;}
    Node* getRoot(){ return root; }

    // Helper methods for inserting
    int HeightOfNode(Node *p);
    int BalanceFactor(Node *p);
    Node* LLRotation(Node *p);
    Node* RRRotation(Node *p);
//    Node* LRRotation(Node *p);
//    Node* RLRotation(Node *p);

    // Insert in Avl tree
    Node* RInsert(Node *p, int key);

    void Preorder(Node *p);
    void Preorder(){ Preorder(root);};


};

int AVL::HeightOfNode(Node *p)
{
    //  hl = Height of left subtree, hr = Height of right subtree

    int hl, hr;
    hl = (p!=NULL && p->lchild!=NULL)? p->lchild->height:0;
    hr = (p!=NULL && p->rchild!=NULL)? p->rchild->height:0;

    // here we consider height of single Node is 1, that's why +1
    return (hl>hr)? hl+1:hr+1;
}

int AVL::BalanceFactor(Node *p)
{
    int hl, hr;

    hl = (p!=NULL && p->lchild!=NULL)? p->lchild->height:0;
    hr = (p!=NULL && p->rchild!=NULL)? p->rchild->height:0;

    return  hl-hr;
}

Node* AVL::LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    // After LL Rotation
    pl->rchild = p;
    p->lchild = plr; // after LL  rotation plr becomes p->left child

    // Update height
    p->height = HeightOfNode(p);
    pl->height = HeightOfNode(pl);

    // Update root
    if(root == p)
        root = pl;

    return pl; // return new root
}

Node* AVL::RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    // After RR Rotation
    pr->lchild = p;
    p->rchild = prl;  // after RR  rotation prl becomes p->right child


    // Update height
    p->height = HeightOfNode(p);
    pr->height = HeightOfNode(pr);

    // Update root
    if(root == p)
        root = pr;

    return pr; // return new root
}

Node* AVL::RInsert(Node *p, int key)
{
    if(p == NULL)
    {
        Node *t = new Node(key);
        t->height = 1;  // Starting height from 1 onwards instead of 0
        if(root==NULL) //update root for recursion(Must Condition for Recursive Insert)
            root = t;
        return t;
    }

    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);

    // Updating height of each node
    p->height = HeightOfNode(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);

//    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
//        return LRRotation(p);
//
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
//
//    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
//        return RLRotation(p);

    return p;
}

void AVL::Preorder(Node *p)
{
    if(p != NULL)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

int main()
{
    // LL Rotation
//    AVL llr;
//    llr.RInsert(llr.getRoot(), 30);
//    llr.RInsert(llr.getRoot(), 40);
//    llr.RInsert(llr.getRoot(), 10);
//    llr.RInsert(llr.getRoot(), 5);
//    llr.RInsert(llr.getRoot(), 15);
//    llr.RInsert(llr.getRoot(), 2);
//
//    cout<<"Preorder of AVL Tree = ";
//    llr.Preorder();
//    cout<<endl;

    // RR Rotation
    AVL rrr;
    rrr.RInsert(rrr.getRoot(), 10);
    rrr.RInsert(rrr.getRoot(), 5);
    rrr.RInsert(rrr.getRoot(), 20);
    rrr.RInsert(rrr.getRoot(), 15);
    rrr.RInsert(rrr.getRoot(), 30);
    rrr.RInsert(rrr.getRoot(), 40);
    rrr.RInsert(rrr.getRoot(), 25);

    cout<<"Preorder of AVL Tree = ";
    rrr.Preorder();
    cout<<endl;



    return 0;
}

       /*
        Before LL Rotation    After LL Rotation

           p=30                    pl=20
          /                       /    \
        pl=20                 plr=10    p=30
        /
      plr=10

    Before LL Rotation    After LL Rotation
         30                 10
        /  \               /  \
      10   40             5   30
      / \                /    / \
     5  15              2   15   40
    /
   2
   preorder:             preorder:
   30 10 5 2 15 40      10 5 2 30 15 40


   Before RR Rotation    After RR Rotation

         10                      20
        / \                     /   \
       5  20                   10    30
          / \                 / \    / \
        15  30               5  15  25 40
            / \
           25  40

    preorder:                preorder:
    10 5 20 15 30 25 40     20 10 5 15 30 25 40

    */
