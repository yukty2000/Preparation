/* GFG Tested

Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. 

*/

/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Computes the diameter of binary tree with given root.  */
int calc_ans(Node *root,int &ans)
{
    if(root==NULL)
        return 0;
    int left_val = calc_ans(root->left,ans);
    int right_val = calc_ans(root->right,ans);
    int temp=left_val+right_val+1;
    if(temp>ans)
        ans=temp;
    return max(left_val,right_val)+1;
}
int diameter(Node* root) {
    if(root==NULL)
        return 0;
    int ans=0;
    int left_val = calc_ans(root->left,ans);
    int right_val = calc_ans(root->right,ans);
    return max(ans,1+left_val+right_val);
}

