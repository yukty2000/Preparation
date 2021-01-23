/* GFG Tested

Given a Binary Tree. Check whether it is a Sum Tree or not.

A Binary Tree is a Sum Tree in which value of each node x is equal to sum of nodes present in its left subtree and right subtree .
An empty tree is also a Sum Tree as sum of an empty tree can be considered to be 0. A leaf node is also considered as a Sum Tree.

*/

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
typedef pair<bool,int> pbi;
pbi SumTree(Node *root)
{
    if(root==NULL)
        return make_pair(true,0);
    if(root->left==NULL&&root->right==NULL)
        return make_pair(true,root->data);
    pbi left_val=SumTree(root->left);
    pbi right_val=SumTree(root->right);
    bool val=(left_val.second+right_val.second)==root->data;
    pbi ans = make_pair((left_val.first&&right_val.first&&val),root->data+left_val.second+right_val.second);
    return ans;
    
}
bool isSumTree(Node* root)
{
     return SumTree(root).first;
}
