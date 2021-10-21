/* GFG
Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.

Example 1:

Input:      
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14
Target Node = 8
K = 2
Output: 10 14 22
Explanation: The three nodes at distance 2
from node 8 are 10, 14, 22.

Example 2:

Input:      
         20
       /    \
      7      24
    /   \
   4     3
        /  
       1    
Target Node = 7
K = 2
Output: 1 24
Your Task:  
You don't need to read input or print anything. Complete the function KDistanceNodes() which takes the root of the tree, target, and K as input parameters and returns a list of nodes at k distance from target in a sorted order.


Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(Height of tree)


Constraints:
1 ≤ N ≤ 10^3
1 ≤ data of node ≤ 10^4
1 ≤ target ≤ 10^4
1 ≤ k ≤ 20

*/

class Solution
{
private:

public:
    int findAns(Node *root,int val,int target,int k,vector<int> &ans)
    {
        if(root==NULL)
            return 0;
        if(val==k)  //from top
        {
            ans.push_back(root->data);
            return 0;
        }
        if(val>0)   // from top but less than k
        {
            findAns(root->left,val+1,target,k,ans);
            findAns(root->right,val+1,target,k,ans);
            return 0;
        }
        if(root->data==target) 
        {
            findAns(root->left,1,target,k,ans);
            findAns(root->right,1,target,k,ans);
            return 1;
        }
        int left=findAns(root->left,val,target,k,ans);
        int right=findAns(root->right,val,target,k,ans);
        // You can get value from only one tree
        if(left>0)
        {
            if(left==k)
            {
                ans.push_back(root->data);
                return 0;
            }
            else
            {
                findAns(root->right,left+1,target,k,ans);
                return left+1;
            }
        }
        if(right>0)
        {
            if(right==k)
            {
                ans.push_back(root->data);
                return 0;
            }
            else
            {
                findAns(root->left,right+1,target,k,ans);
                return right+1;
            }
        }
        return 0;
        
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int> ans;
        findAns(root,0,target,k,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
