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

bool isSymmetric(Tree *t1, Tree *t2)
{
    if(t1 == NULL || t2 == NULL)
        return t1 == t2;
    
    if(t1->data != t2->data)
        return false;
    
    return isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
}

int main()
{

    Tree *root = buildTree();

    /*      4
          /   \
         3     3
        / \    / \
       1   8  8   1

    */
   // 4 3 1 -1 -1 8 -1 -1 3 8 -1 -1 1 -1 -1

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    bool ans = root == NULL || isSymmetric(root->left, root->right);

    cout << ans << endl;
    return 0;

}