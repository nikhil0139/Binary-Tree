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

Tree* lcs(Tree *x, int a, int b)
{
    if(x==NULL || x->data == a || x->data == b)
        return x;
    Tree* left = lcs(x->left, a, b);
    Tree* right = lcs(x->right, a, b);

    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    else
        return x;
}

int main()
{

    Tree *root = buildTree();

    /*      4
          /   \
         2     3
        / \    / \
       5   7  8   1

    */
   // 4 2 5 -1 -1 7 -1 -1 3 8 -1 -1 1 -1 -1

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    Tree *ans = lcs(root, 7, 2);
    cout << ans->data << endl;
    return 0;

}