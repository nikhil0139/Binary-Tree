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

class HDPair{
    public:
        int height;
        int diameter;
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

HDPair diameter_Tree(Tree* root){
    HDPair p;
    if(root == NULL){
        p.height = 0;
        p.diameter = 0;
        return p;
    }
        
    HDPair l = diameter_Tree(root->left);
    HDPair r = diameter_Tree(root->right);
    
    p.height = max(l.height, r.height) + 1;

    int D1 = l.height + r.height + 1;
    int D2 = l.diameter;
    int D3 = r.diameter;

    p.diameter = max(D1, max(D2, D3));
    return p;
}

// Another Approach

int height_Tree(Tree* root, int *diameter){
    if(root == NULL)
        return 0;

    int h1 = height_Tree(root->left, diameter);
    int h2 = height_Tree(root->right, diameter);
    *diameter = max(*diameter, h1+h2+1);
    // diameter is our final answer
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


    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    HDPair p = diameter_Tree(root);
    cout << p.diameter << endl;

    // Another Approach
    int diameter = 0;
    int ans = height_Tree(root,&diameter);
    cout << diameter << endl;
    
    return 0;

}