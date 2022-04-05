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


Tree *buildTree(vector<int>post, vector<int>in, int start, int end){
    if(start > end)
        return NULL;
    
    static int index = end;
    int currEle = post[index];
    index--;
    Tree *n = new Tree(currEle);

    if(start == end)
        return n;

    int pos = search(in, start, end, currEle);
    n->right = buildTree(post, in, pos+1, end);
    n->left = buildTree(post, in, start, pos-1);
    return n;
}

int main(){

    int n;
    cin >> n;

    vector<int>post(n), in(n);

    for(int i=0;i<n;i++){
        cin >> post[i];
    }

    for(int i=0;i<n;i++){
        cin >> in[i];
    }

    Tree *root = buildTree(post, in, 0, n-1);

    inorder(root);

    return 0;
}