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

bool path(Tree *x, int node, vector<int>&ans)
{
    if(x==NULL)
        return false;
    ans.push_back(x->data);
    if(x->data == node)
        return true;
    if(path(x->left, node, ans) || path(x->right, node, ans))
        return true;
    ans.pop_back();
    return false;
}

int main()
{

    Tree *root = buildTree();

    /*      4
          /   \
         3     3
        / \    / \
       1   7  8   1

    */
   // 4 3 1 -1 -1 7 -1 -1 3 8 -1 -1 1 -1 -1

   int x;
   cin >> x;

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    vector<int>ans;
    path(root, x, ans);
    for(auto i : ans)
        cout << i << " ";
    return 0;

}