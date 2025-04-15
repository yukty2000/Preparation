#include <bits/stdc++.h>

using namespace std;
using lli = long long int;
using pii = pair<int,int>;

// AVL Trees

struct Node
{
    int data;
    Node *left,*right;
    int height;

    Node(int val)
    {
        data=val;
        height=0;
        left=right=NULL;
    }
};

Node * rightRotate(Node *root)
{
    Node *newRoot = root->left;
    Node *temp=newRoot->right;
    root->left=temp;
    newRoot->right=root;
    root->height=1+max(root->left->height,root->right->height);
    newRoot->height=1+max(newRoot->left->height,newRoot->right->height);
    return newRoot;
}

Node * leftRotate(Node *root)
{
    Node *newRoot = root->right;
    Node *temp=newRoot->left;
    root->right=temp;
    newRoot->left=root;
    root->height=1+max(root->left->height,root->right->height);
    newRoot->height=1+max(newRoot->left->height,newRoot->right->height);
    return newRoot;
}

Node *insertVal(Node *root,int val)
{
    if(root==NULL)
    {
        Node *temp=new Node(val);
        return temp;
    }
    if(root->data<val)
    {
        root->right=insertVal(root->right,val);
    }
    else
    {
        root->left=insertVal(root->left,val);
    }
    int balance=0;
    if(root->left!=NULL)
        balance+=root->left->height;
    if(root->right!=NULL)
        balance-=root->right->height;
    if(balance>1) // left subtree is heavier
    {
        // root->left exists
        int leftWeight=root->left->left!=NULL? root->left->left->height : 0;
        int rightWeight=root->left->right!=NULL? root->left->right->height : 0;
        if(leftWeight>rightWeight) // LL type -> R rotation
            root=rightRotate(root);
        else // LR type -> First L rotation on root->left, then R rotation on root
        {
            root->left=leftRotate(root->left);
            root=rightRotate(root);
        }
    }
    else if(balance<-1) // right subtree is heavier
    {
        //root->right exists
        int leftWeight=root->right->left!=NULL? root->right->left->height : 0;
        int rightWeight=root->right->right!=NULL? root->right->right->height : 0;
        if(rightWeight>leftWeight) // RR type -> L rotation
            root=leftRotate(root);
        else // RL type -> First R rotation on root->right, then L rotation on root
        {
            root->right=rightRotate(root->right);
            root=leftRotate(root);
        }
    }
    return root;
}
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    Node *root = NULL;
    for(int i=0;i<n;i++)
    {
        root = insertVal(root,v[i]);
        inorder(root);
        cout<<endl;
    }


    cout<<endl;
    return 0;
}
