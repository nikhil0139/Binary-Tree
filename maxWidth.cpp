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

int width(Tree* x)
{
    int ans = 0;
    if(x==NULL)  
        return ans;
    queue<pair<Tree *, int>>q;
    q.push({x, 0});
    while(!q.empty()){
        int n = q.size();
        int mini = q.front().second;
        int first, last;
        for(int i=0;i<n;i++){
            int starting = q.front().second - mini;
            Tree *a = q.front().first;
            q.pop();
            if(i==0)
                first = starting;
            if(i==n-1)
                last = starting;
            if(a->left != NULL)
                q.push({a->left, 2*starting+1});
            if(a->right != NULL)
                q.push({a->right, 2*starting+2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{

    Tree *root = buildTree();

    /*      4
          /   \
         2     3
        / \    / \
       5   7  8   1

    */
   // 4 2 5 -1 -1 7 -1 -1 3 8 -1 -1 1 -1 -1

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    cout << width(root) << endl;
    return 0;

}