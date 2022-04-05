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

vector<vector<int>> levelOrder(Tree *x){
    vector<vector<int>> ans;
    if(x==NULL)  return ans;
    queue<Tree *>q;
    q.push(x);
    while(!q.empty()){
        int n = q.size();
        vector<int>level;
        for(int i=0;i<n;i++){
            Tree *a = q.front();
            q.pop();

            if(a->left != NULL)
                q.push(a->left);
            if(a->right != NULL)
                q.push(a->right);
            level.push_back(a->data);
        }
        ans.push_back(level);
    }
    return ans;
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

    vector<vector<int>> ans = levelOrder(root);

    cout << "Level Order Traversal : ";
    for(auto i : ans)
        for(auto j : i)
            cout << j << " "; 

    return 0;
}