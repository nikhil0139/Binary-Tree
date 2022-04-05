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


void flatten(Tree* x)
{
    stack<Tree*>s;
    s.push(x);
    Tree *ans;
    while(!s.empty())
    {
        ans = s.top();
        s.pop();
        if(ans->right)
            s.push(ans->right);
        if(ans->left)
            s.push(ans->left);
        
        if(!s.empty()){
            ans->right = s.top();
        }
        ans->left = NULL;
    }
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

    flatten(root);

    while(root)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
    return 0;

}