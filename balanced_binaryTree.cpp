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

int balanced_Tree(Tree* root){
    if(root == NULL)
        return 0;

    int h1 = balanced_Tree(root->left);
    if(h1 == -1)
        return -1;
    int h2 = balanced_Tree(root->right);
    if(h2 == -1)
        return -1;

    if(abs(h1-h2) > 1)
        return -1;

    return max(h1, h2) + 1;
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

    int height = balanced_Tree(root);

    if(height!=-1)
        cout << "Yes tree is balanced" << endl;
    else
        cout << "No tree is not balanced" << endl;
    
    return 0;

}