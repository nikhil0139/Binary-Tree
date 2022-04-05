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

vector<vector<int>>zigzagtraversal(Tree *t){
    vector<vector<int>>ans;
    if(t == NULL){
        return ans;
    }
    queue<Tree *>q;
    q.push(t);
    bool leftRight = true;

    while(!q.empty())
    {
        int n = q.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            Tree* x = q.front();
            q.pop();
            int idx = (leftRight) ? i : (n - 1 - i); // to find index whether fill from L to R or R to L
            temp[idx] = x->data;
            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
        }
        ans.push_back(temp);
        leftRight = !leftRight; // to change flag value
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
   // 4 3 7 -1 -1 8 -1 -1 5 9 -1 -1 1 -1 -1

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    vector<vector<int>>ans = zigzagtraversal(root);
    for(auto i : ans){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;

}