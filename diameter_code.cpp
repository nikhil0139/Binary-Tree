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

int height_Tree(Tree* root){
    if(root == NULL)
        return 0;

    int h1 = height_Tree(root->left);
    int h2 = height_Tree(root->right);

    return max(h1, h2) + 1;
}

int diameter_Tree(Tree* root){
    if(root == NULL)
        return 0;

    int d1 = height_Tree(root->left) + height_Tree(root->right) + 1;
    int d2 = diameter_Tree(root->left);
    int d3 = diameter_Tree(root->right);
    return max(d1, max(d2, d3));
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

    int diameter = diameter_Tree(root);

    cout << diameter << endl;
    
    return 0;

}