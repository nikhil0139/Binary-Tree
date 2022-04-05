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

void preorder(Tree *x)
{
    if (x != NULL)
    {
        cout << x->data << " ";
        preorder(x->left);
        preorder(x->right);
    }
}

vector<int> iteraivePreorder(Tree *x)
{
    vector<int> ans;
    stack<Tree *> st;
    st.push(x);
    while (!st.empty())
    {
        Tree *ptr = st.top();
        st.pop();
        ans.push_back(ptr->data);
        if (ptr->right)
            st.push(ptr->right);
        if (ptr->left)
            st.push(ptr->left);
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

    preorder(root);
    cout << endl;
    vector<int> v = iteraivePreorder(root);
    for (auto it : v)
        cout << it << " ";

    return 0;
}