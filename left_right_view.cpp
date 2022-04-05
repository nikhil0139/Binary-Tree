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

void leftView(Tree *root, int level, vector<int>&ans)
{
    if(root == NULL)
        return;
    if(ans.size() == level)
        ans.push_back(root->data);
    leftView(root->left, level + 1, ans);
    leftView(root->right, level + 1, ans);
}

void rightView(Tree *root, int level, vector<int>&ans)
{
    if(root == NULL)
        return;
    if(ans.size() == level)
        ans.push_back(root->data);
    rightView(root->right, level + 1, ans);
    rightView(root->left, level + 1, ans);
}

int main()
{

    Tree *root = buildTree();

    /*      4
          /   \
         3     5
        / \    / \
       7   8  9   1
      /   / \
     1   6   2

    */
   // 4 3 7 1 -1 -1 -1 8 6 -1 -1 2 -1 -1 5 9 -1 -1 1 -1 -1

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    vector<int>left, right;
    leftView(root, 0, left);
    rightView(root, 0, right);

    for(auto i : left)
        cout << i << " ";
    
    cout << endl;

    for(auto i : right)
        cout << i << " ";
    return 0;

}