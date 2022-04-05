// tree is balanced if for every node diff bw left and right height <= 1

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

void sumReplace(Tree* root){
    if(root == NULL)
        return;
    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left!=NULL){
        root->data += root->left->data;
    }

    if(root->right!=NULL){
        root->data += root->right->data;
    }
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
   // 4 3 7 -1 -1 8 -1 -1 5 9 -1 -1 1 -1 -1

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    sumReplace(root);

    inorder(root);
    cout << endl;
    
    return 0;

}