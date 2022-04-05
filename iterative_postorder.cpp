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

void postorder(Tree *x){
    if(x==NULL)
        return;
    postorder(x->left);
    postorder(x->right);
    cout << x->data << " ";
}

vector<int> iteraivePostorder(Tree *x)
{
    vector<int> ans;
    stack<Tree *> st1, st2;
    st1.push(x);
    Tree *temp = x;
    while (!st1.empty())
    {
        temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left)
            st1.push(temp->left);
        if(temp->right)
            st1.push(temp->right);
        
    }
    while(!st2.empty()){
        temp = st2.top();
        ans.push_back(temp->data);
        st2.pop();
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

    postorder(root);
    cout << endl;
    vector<int> v = iteraivePostorder(root);
    for (auto it : v)
        cout << it << " ";

    return 0;
}