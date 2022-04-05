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

bool leaf(Tree *root){
    if(root->left == NULL && root->right == NULL)
        return true;
    return false;
}

void leftBoundary(Tree* root, vector<int>&ans){
    Tree* x = root->left;
    while(x){
        if(leaf(x) == false){
            ans.push_back(x->data);
        }
        if(x->left)
            x = x->left;
        else
            x = x->right;
    }
}

void leafNodes(Tree* root, vector<int>&ans){
    if(leaf(root) == true){
        ans.push_back(root->data);
        return;
    }
    if(root->left)
        leafNodes(root->left, ans);
    if(root->right)
        leafNodes(root->right, ans);
}

void rightBoundary(Tree* root, vector<int>&ans){
    Tree* x = root->right;
    stack<int>s;
    while(x){
        if(leaf(x) == false){
            s.push(x->data);
        }
        if(x->right)
            x = x->right;
        else
            x = x->left;
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
}

vector<int>printBoundary(Tree* root){
    vector<int>ans;
    if(root == NULL)
        return ans;
    if(leaf(root) == false)
        ans.push_back(root->data);
    leftBoundary(root, ans);
    leafNodes(root, ans);
    rightBoundary(root, ans);
    return ans;
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

    vector<int>ans = printBoundary(root);
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;

}