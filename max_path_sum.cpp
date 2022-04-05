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

int pathSum(Tree* t, int &ans){
    if(t == NULL)
        return 0;
    int lSum = max(0, pathSum(t->left, ans));
    int rSum = max(0, pathSum(t->right, ans));
    ans = max(ans, t->data + lSum + rSum);
    return t->data + max(lSum, rSum);
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

    int ans = 0;

    int maxi = pathSum(root, ans);

    cout << ans << endl;
    
    return 0;

}