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
    void printRoot(){ cout<<root->data; }

    // Helper methods for inserting
    int HeightOfNode(Node *p);
    int BalanceFactor(Node *p);
    Node* LLRotation(Node *p);
    Node* RRRotation(Node *p);
    Node* LRRotation(Node *p);
    Node* RLRotation(Node *p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);

    // Insert in Avl tree
    Node* RInsert(Node *p, int key);

    // Delete
    Node* Delete(Node* p, int key); // for delete we require Inpre or InSucc of that node

    void Preorder(Node *p);
    void Preorder(){ Preorder(root);};

    void Inorder(Node *p);
    void Inorder(){ Inorder(root);};


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

Node* AVL::LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    // After LR Rotation
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    // Update height
    pl->height = HeightOfNode(pl);
    p->height = HeightOfNode(p);
    plr->height = HeightOfNode(plr);

    // Update root
    if(root == p)
        root = plr;

    return plr; // return new root
}

Node* AVL::RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    // After LR Rotation
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    // Update height
    pr->height = HeightOfNode(pr);
    p->height = HeightOfNode(p);
    prl->height = HeightOfNode(prl);

    // Update root
    if(root == p)
        root = prl;

    return prl; // return new root
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

    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);

    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);

    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);

    return p;
}

Node* AVL::InPre(Node* p)
{
//    If its left subtree is not null, Then predecessor will be the right most
//    child of left subtree or left child itself.
    while(p!=NULL && p->rchild!=NULL)
        p = p->rchild;

    return p;
}

Node* AVL::InSucc(Node* p)
{
//    If its right subtree is not null, Then successor will be the left most child
//    of right subtree or right child itself.
    while(p!=NULL && p->lchild!=NULL)
        p = p->lchild;

    return p;
}

Node* AVL::Delete(Node* p, int key)
{
    if(p == NULL)
        return NULL;

    // Leaf node condition
    if(p->lchild==NULL && p->rchild==NULL)
    {
        // if only one Node present in bst
        if(p==root)
            root = NULL;
        delete p;
        p = NULL;
        return NULL;
    }

    // Search for Key
    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        // Based on Height of Subtree, we decide whether we want to delete from Left side or Right side
        //Left side is Have greater Height
        Node* q;
        if(HeightOfNode(p->lchild) > HeightOfNode(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data); // Delete q;
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data); // Delete q;
        }
    }

    // Update Height after deleting
    p->height = HeightOfNode(p);

    // Balance Factor and Rotation
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
    {
        // L1 Rotation
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
    {
        // L-1 Rotation
        return LRRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0)
    {
        // L0 Rotation
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
    {
        // R1 Rotation
        return RLRotation(p);
    }
     else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
    {
        // R-1 Rotation
        return RRRotation(p);
    }
     else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==0)
    {
        // R0 Rotation
        return RRRotation(p);
    }

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

void AVL::Inorder(Node *p)
{
    if(p != NULL)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
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

//    // RR Rotation
//    AVL rrr;
//    rrr.RInsert(rrr.getRoot(), 10);
//    rrr.RInsert(rrr.getRoot(), 5);
//    rrr.RInsert(rrr.getRoot(), 20);
//    rrr.RInsert(rrr.getRoot(), 15);
//    rrr.RInsert(rrr.getRoot(), 30);
//    rrr.RInsert(rrr.getRoot(), 40);
//    rrr.RInsert(rrr.getRoot(), 25);
//
//    cout<<"Preorder of AVL Tree = ";
//    rrr.Preorder();
//    cout<<endl;

//    // LR Rotation
//    AVL lrr;
//    lrr.RInsert(lrr.getRoot(), 50);
//    lrr.RInsert(lrr.getRoot(), 10);
//    lrr.RInsert(lrr.getRoot(), 20);
//
//    cout<<"Preorder of AVL Tree = ";
//    lrr.Preorder();
//    cout<<endl;
//    lrr.printRoot();

//    // RL Rotation
//    AVL rlr;
//    rlr.RInsert(rlr.getRoot(), 20);
//    rlr.RInsert(rlr.getRoot(), 50);
//    rlr.RInsert(rlr.getRoot(), 30);
//
//    cout<<"Preorder of AVL Tree = ";
//    rlr.Preorder();
//    cout<<endl;
//    rlr.printRoot();

    AVL tree;

    int A[] = {10, 20, 30, 25, 28, 27, 5};
    int sz = sizeof(A)/sizeof(A[0]);
    for (int i=0; i<sz; i++){
        tree.RInsert(tree.getRoot(), A[i]);
    }

    cout<<"Inorder of AVL Tree = ";
    tree.Inorder();

    cout<<endl;

    tree.Delete(tree.getRoot(), 28);

    cout<<"Inorder of AVL Tree = ";
    tree.Inorder();

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


    Before LR Rotation    After LR Rotation

           p=30                    plr=10
          / \                     /    \
        pl=20                 pl=20    p=30
       / \                      \       /
         plr=10
         / \

    Before    In-between    After
    LR        LR            LR
     50p           50p          20
     /\             /\         / \
    10pl         20plr        10  50
    /\            /  \        /\  /\
      20plr      10pl
      /\         /\
    preorder:                preorder:
    50 10 20                 20 10 50


   Before LR Rotation    After LR Rotation

         10                      20
        /  \                     /   \
       5    20                   10    30
      / \   / \              / \    / \
     2   7 15 30            5  15  25 40


    preorder:                preorder:
    10 5 20 15 30 25 40     20 10 5 15 30 25 40

    Before    In-between    After
    RL        RL            RL
    20      20       30
     50      30     20 50
    30         50

    */
