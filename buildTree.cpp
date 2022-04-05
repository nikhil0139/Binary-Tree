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

void preorder(Tree *x){
    if(x!=NULL){
        cout << x->data << " ";
        preorder(x->left);
        preorder(x->right);
    }
}

void postorder(Tree *x){
    if(x==NULL)
        return;
    postorder(x->left);
    postorder(x->right);
    cout << x->data << " ";
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

    cout << "Preorder Traversal : ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal : ";
    postorder(root);
    cout << endl;
    
    return 0;

}