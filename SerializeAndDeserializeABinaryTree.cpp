/* GFG
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to the tree and returns it.
Note: The structure of the tree must be maintained. Multiple nodes can have the same data.

Example 1:

Input:
      1
    /   \
   2     3
Output: 2 1 3
Example 2:

Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 40 20 60 10 30
Your Task:
The task is to complete two function serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000

*/
class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> ans;
        queue<Node *> q;
        q.push(root);
        ans.push_back(root->data);
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            if(temp->left!=NULL)
            {
                q.push(temp->left);
                ans.push_back(temp->left->data);
            }
            else
            {
                ans.push_back(-1);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
                ans.push_back(temp->right->data);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
        queue<Node *> parent;
        Node *root=new Node(A[0]);
        parent.push(root);
        int i=1;
        while(!parent.empty()&&i<A.size())
        {
            Node *temp=parent.front();
            parent.pop();
            if(A[i]!=-1)
            {
                Node *left=new Node(A[i]);
                temp->left=left;
                parent.push(left);
            }
            i++;
            if(A[i]!=-1)
            {
                Node *right=new Node(A[i]);
                temp->right=right;
                parent.push(right);
            }
            i++;
        }
        return root;
    }
};
