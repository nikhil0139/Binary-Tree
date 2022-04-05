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

vector<vector<int>>verticalLevel(Tree* root){
    map<int, map<int, multiset<int>>>node;
    queue<pair<Tree*, pair<int, int>>>q;
    q.push({root, {0, 0}});
    while(!q.empty())
    {
        auto x = q.front();
        q.pop();
        Tree* temp = x.first;
        int ver = x.second.first, lev = x.second.second;
        node[ver][lev].insert(temp->data);
        if(temp->left)
        {
            q.push({temp->left, {ver-1, lev+1}});
        }
        if(temp->right)
        {
            q.push({temp->right, {ver+1, lev+1}});
        }
    }
    vector<vector<int>>ans;
    for(auto i : node)
    {
        vector<int>temp;
        for(auto j : i.second){
            temp.insert(temp.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(temp);
    }
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

    vector<vector<int>>ans = verticalLevel(root);
    for(auto i : ans){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;

}