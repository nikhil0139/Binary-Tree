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

vector<int> iteraiveInorder(Tree *x)
{
    vector<int> ans;
    stack<Tree *> st;
    Tree *temp = x;
    while (true)
    {
        if(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty())
                break;
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
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

    inorder(root);
    cout << endl;
    vector<int> v = iteraiveInorder(root);
    for (auto it : v)
        cout << it << " ";

    return 0;
}