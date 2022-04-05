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

vector<int>topView(Tree* root){
    map<int, int>mp;
    queue<pair<Tree*, int>>q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto x = q.front();
        q.pop();
        Tree* temp = x.first;
        int ver = x.second;
        if(mp.find(ver) == mp.end())
            mp[ver] = temp->data;
        if(temp->left)
        {
            q.push({temp->left, ver-1});
        }
        if(temp->right)
        {
            q.push({temp->right, ver+1});
        }
    }
    vector<int>ans;
    for(auto i : mp)
    {
        ans.push_back(i.second);
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

    vector<int>ans = topView(root);
    for(auto i : ans)
        cout << i << " ";
    return 0;

}