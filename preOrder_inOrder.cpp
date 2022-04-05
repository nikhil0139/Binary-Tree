#include<bits/stdc++.h>
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

void inorder(Tree *x){
    if(x==NULL)
        return;
    inorder(x->left);
    cout << x->data << " ";
    inorder(x->right);
}

int search(vector<int>inorder, int start, int end, int ele){
    for(int i=start;i<=end;i++){
        if(inorder[i] == ele)
            return i;
    }
    return -1;
}


Tree *buildTree(vector<int>pre, vector<int>in, int start, int end){
    if(start > end)
        return NULL;
    
    static int index = 0;
    int currEle = pre[index];
    index++;
    Tree *n = new Tree(currEle);

    if(start == end)
        return n;

    int pos = search(in, start, end, currEle);
    n->left = buildTree(pre, in, start, pos-1);
    n->right = buildTree(pre, in, pos+1, end);
    return n;
}

int main(){

    int n;
    cin >> n;

    vector<int>pre(n), in(n);

    for(int i=0;i<n;i++){
        cin >> pre[i];
    }

    for(int i=0;i<n;i++){
        cin >> in[i];
    }

    Tree *root = buildTree(pre, in, 0, n-1);

    inorder(root);

    return 0;
}