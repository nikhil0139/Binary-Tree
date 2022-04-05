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

pair<int, bool> height_balanced(Tree* root){
    pair<int, bool> p;
    if(root == NULL){
        p.first = 0;
        p.second = true;
        return p;
    }
        
    pair<int, bool> l = height_balanced(root->left);
    pair<int, bool> r = height_balanced(root->right);
    
    int height = max(l.first, r.first) + 1;

    if(abs(l.first - r.first) <= 1 && l.second && r.second){
        return {height, true};
    }
    return {height, false};
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

    pair<int, bool> p = height_balanced(root);

    cout << p.first << " " << p.second << endl;
    
    return 0;

}