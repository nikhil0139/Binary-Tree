#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;

    Tree(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Tree *buildTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;
        
    Tree *n = new Tree(x);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void inorder(Tree *x){
    if(x==NULL)
       return;
    inorder(x->left);
    cout << x->data << " ";
    inorder(x->right);
}

int newTree(Tree *root){
    if(root == NULL){
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return root->data;
    }

    int leftSum = newTree(root->left);
    int rightSum = newTree(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;
    return root->data + temp;
}

int main()
{

    Tree *root = buildTree();

    /*      4
          /  \
         3    5
        / \   / \
       7   8 9   1
    */


    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    int x = newTree(root);

    inorder(root);
    
    return 0;

}