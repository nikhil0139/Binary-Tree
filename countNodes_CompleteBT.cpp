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

int leftHeight(Tree* node){
    int cnt = 0;
    while(node){
        cnt++;
        node = node->left;
    }
    return cnt;
}

int rightHeight(Tree* node){
    int cnt = 0;
    while(node){
        cnt++;
        node = node->right;
    }
    return cnt;
}


int count(Tree* x){
    if(x==NULL)
        return 0;
    int left = leftHeight(x);
    int right = rightHeight(x);

    if(left == right)
        return pow(2, left) - 1;
    
    return 1 + count(x->left) + count(x->right);
}

int main()
{

    Tree *root = buildTree();

    /*      9
          /   \
         8     6
        / \    / \
       3   4  2   1

    */
   // 9 8 3 -1 -1 4 -1 -1 6 2 -1 -1 

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    cout << count(root) << endl;
    return 0;

}