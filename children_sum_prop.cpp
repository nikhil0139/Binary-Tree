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

void csp(Tree* x)
{
    if(x==NULL)
        return;
    int sum = 0;
    if(x->left)
        sum+=x->left->data;
    if(x->right)
        sum+=x->right->data;

    if(sum < x->data){
        if(x->left)
            x->left->data = x->data;
        else if(x->right)
            x->right->data = x->data;
    }
    else{
        x->data = sum;
    }

    csp(x->left);
    csp(x->right);

    int val = 0;
    if(x->left)
        val += x->left->data;
    if(x->right)
        val += x->right->data;
    if(x->left || x->right)
        x->data = val;
}

int main()
{

    Tree *root = buildTree();

    /*      9
          /   \
         8     6
        / \    / \
       3   4  2   1

    */
   // 9 8 3 -1 -1 4 -1 -1 6 2 -1 -1 1 -1 -1

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    csp(root);
    inorder(root);
    return 0;

}