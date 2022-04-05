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

bool identical(Tree* a, Tree* b){
    if(a==NULL || b == NULL)
        return a==b;
    
    return (a->data == b->data && identical(a->left, b->left) && identical(a->right, b->right));
}

int main()
{

    Tree *root1 = buildTree();
    Tree *root2 = buildTree();

    /*      4
          /  \
         3    5
        / \   / \
       7   8 9   1
    */
   // 4 3 7 -1 -1 8 -1 -1 5 9 -1 -1 1 -1 -1

    cout << "Inorder Traversal : " << endl;
    inorder(root1);
    cout << endl;
    inorder(root2);
    cout << endl;

    cout << identical(root1, root2) << endl;
    
    return 0;

}