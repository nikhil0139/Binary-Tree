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

int sumAtKthLevel(Tree *x, int k){
    int ans = 0, i = -1;
    if(x==NULL)  return ans;
    queue<Tree *>q;
    q.push(x);
    while(!q.empty()){
        int n = q.size();
        vector<int>level;
        i++;
        for(int i=0;i<n;i++){
            Tree *a = q.front();
            q.pop();

            if(a->left != NULL)
                q.push(a->left);
            if(a->right != NULL)
                q.push(a->right);
            level.push_back(a->data);
        }

        if(i==k)
            ans = accumulate(level.begin(), level.end(), 0);
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

    int k;
    cin >> k;

    int ans = sumAtKthLevel(root, k);

    cout << "Sum at level k : " << ans << endl;

    return 0;

}