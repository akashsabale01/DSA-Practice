#include <iostream>
#include <queue>
#include <stack>
#include <vector>

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

    void PreorderIterative(){PreorderIterative(root);};
    void PreorderIterative(Node *p);

    void InorderIterative(){InorderIterative(root);};
    void InorderIterative(Node *p);

    void PostorderIterative(){PostorderIterative(root);};
    void PostorderIterative(Node *p);

    void PostorderIterativeUsing2Stack(){PostorderIterativeUsing2Stack(root);};
    void PostorderIterativeUsing2Stack(Node *p);

    void PostorderIterativeUsing1Stack(){PostorderIterativeUsing1Stack(root);};
    void PostorderIterativeUsing1Stack(Node *p);

    int Height() { return Height(root); };
    int Height(Node *p);

    int CountOfNodes() { return CountOfNodes(root); };
    int CountOfNodes(Node *p);

    int CountOfLeafNodes() { return CountOfLeafNodes(root); };
    int CountOfLeafNodes(Node *p);

    int CountOfNodesWithDegreeExact2() { return CountOfNodesWithDegreeExact2(root); };
    int CountOfNodesWithDegreeExact2(Node *p);

    int CountOfNodesWithDegree1OrMore() { return CountOfNodesWithDegree1OrMore(root); };
    int CountOfNodesWithDegree1OrMore(Node *p);

    int CountOfNodesWithDegree1() { return CountOfNodesWithDegree1(root); };
    int CountOfNodesWithDegree1(Node *p);
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

//
//void Tree::PostorderIterative(Node *p)
//{
//    stack<long int> stk;
//    long int temp;
//
//    while(p!=NULL || !stk.empty())
//    {
//        if(p!=NULL)
//        {
//            stk.push((long int)p);
//            p = p->lchild;
//        }
//        else
//        {
//            temp = stk.top();
//            stk.pop();
//            if(temp>0)
//            {
//                stk.push(-temp);
//                p = ((Node*)temp)->rchild;
//            }
//            else
//            {
//                cout<<((Node*)(-temp))->data<<" ";
//                p = NULL;
//            }
//        }
//    }
//
//}


void Tree::PostorderIterativeUsing2Stack(Node *p)
{
    if(p==NULL) return;

    stack<Node*> stk1, stk2;
    stk1.push(p);
    Node* temp;

    while(!stk1.empty())
    {
        temp = stk1.top();
        stk1.pop();
        stk2.push(temp);

        if((stk2.top())->lchild != NULL)
        {
            stk1.push((stk2.top())->lchild);
        }
        if((stk2.top())->rchild != NULL)
        {
            stk1.push((stk2.top())->rchild);
        }
    }
    while(!stk2.empty())
    {
        cout<<(stk2.top())->data<<" ";
        stk2.pop();
    }
}

void Tree::PostorderIterativeUsing1Stack(Node *p)
{
    if(p == NULL) return;

    vector<int> postorderOutput;
    stack<Node*> stk;
    Node* current = p; // p is root

    while(current!=NULL || !stk.empty())
    {
        if(current != NULL)
        {
            stk.push(current);
            current = current->lchild;
        }
        else
        {
            Node* temp = stk.top()->rchild;
            if(temp == NULL)
            {
                temp = stk.top();
                stk.pop();
                postorderOutput.push_back(temp->data);
                while(!stk.empty() && temp==stk.top()->rchild)
                {
                    temp = stk.top();
                    stk.pop();
                    postorderOutput.push_back(temp->data);
                }
            }
            else
            {
                current = temp;
            }
        }
    }

    // display vector
    for(int i=0; i<int(postorderOutput.size()); i++)
    {
        cout<<postorderOutput[i]<<" ";
    }
}

int Tree::Height(Node *p)
{
    if(p==NULL) return 0;

    int lHeight = Height(p->lchild);
    int rHeight = Height(p->rchild);

    return (lHeight>rHeight)? lHeight+1:rHeight+1;
}

int Tree::CountOfNodes(Node *p)
{
    if(p==NULL)
        return 0;

    return CountOfNodes(p->lchild) + CountOfNodes(p->rchild) + 1;
}

int Tree::CountOfLeafNodes(Node *p)
{
    if(p==NULL)
        return 0;
    // condition for leaf node i.e. No childrens
    if(p->lchild==NULL && p->rchild==NULL)
        return CountOfLeafNodes(p->lchild) + CountOfLeafNodes(p->rchild) + 1;

    return CountOfLeafNodes(p->lchild) + CountOfLeafNodes(p->rchild);
}

int Tree::CountOfNodesWithDegreeExact2(Node *p)
{
    if(p==NULL)
        return 0;
    // Nodes having degree exact 2
    if(p->lchild!=NULL && p->rchild!=NULL)
        return CountOfNodesWithDegreeExact2(p->lchild) + CountOfNodesWithDegreeExact2(p->rchild) + 1;

    return CountOfNodesWithDegreeExact2(p->lchild) + CountOfNodesWithDegreeExact2(p->rchild);
}

int Tree::CountOfNodesWithDegree1OrMore(Node *p)
{
    if(p==NULL)
        return 0;
    // Nodes having degree exact 2
    if(p->lchild!=NULL || p->rchild!=NULL)
        return CountOfNodesWithDegree1OrMore(p->lchild) + CountOfNodesWithDegree1OrMore(p->rchild) + 1;

    return CountOfNodesWithDegree1OrMore(p->lchild) + CountOfNodesWithDegree1OrMore(p->rchild);
}

int Tree::CountOfNodesWithDegree1(Node *p)
{
    if(p==NULL)
        return 0;

//    if((p->lchild!=NULL && p->rchild==NULL) || (p->lchild!=NULL && p->rchild==NULL))
//        return CountOfNodesWithDegree1(p->lchild) + CountOfNodesWithDegree1(p->rchild) + 1;

    if((p->lchild!=NULL )^(p->rchild!=NULL))
        return CountOfNodesWithDegree1(p->lchild) + CountOfNodesWithDegree1(p->rchild) + 1;

    return CountOfNodesWithDegree1(p->lchild) + CountOfNodesWithDegree1(p->rchild);
}
// we know condition for Nodes With Degree Exact 1 is below
// p->lchild!=NULL && p->rchild==NULL) || (p->lchild!=NULL && p->rchild==NULL)
// above can be simplified as
//  LR' + L'R => L^R  ....XOR of L and R
//  p->lchild!=NULL ^ p->rchild==NULL


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

//    cout<<endl<<"Iterative Preorder Traversal: ";
//    t.PreorderIterative();
//
//    cout<<endl<<"Iterative Inorder Traversal: ";
//    t.InorderIterative();

//    cout<<endl<<"Iterative Postorder Traversal: ";
//    t.PostorderIterative();
//    t.PostorderIterativeUsing2Stack();
//    t.PostorderIterativeUsing1Stack();

    cout<<endl<<"Height of Tree : "<<t.Height();
    cout<<endl<<"Count of Nodes : "<<t.CountOfNodes();
    cout<<endl<<"Count of Leaf Nodes : "<<t.CountOfLeafNodes();
    cout<<endl<<"Count of Nodes With Degree Exact 2 : "<<t.CountOfNodesWithDegreeExact2();
    cout<<endl<<"Count of Nodes With Degree 1 Or More : "<<t.CountOfNodesWithDegree1OrMore();
    cout<<endl<<"Count of Nodes With Degree 1 : "<<t.CountOfNodesWithDegree1();

    cout<<endl;

    return 0;
}
