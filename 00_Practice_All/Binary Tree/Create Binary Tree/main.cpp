#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Build tree by taking input from user for each node
Node *buildTree(Node *root)
{
    int inputData;
    cout << "Enter data = ";
    cin >> inputData;

    root = new Node(inputData);

    if (inputData == -1) // base case
        return NULL;

    cout << "Enter data for inserting in left of " << inputData << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << inputData << endl;
    root->right = buildTree(root->right);

    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    cout << "Pre order : ";
    preOrder(root);

    cout << "In order : ";
    inOrder(root);

    cout << "Post order : ";
    postOrder(root);

    return 0;
}

// https://youtu.be/5NiXlPrLslg