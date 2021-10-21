/* GFG
Given inorder and level-order traversals of a Binary Tree, construct the Binary Tree and return the root Node. 

Input:
First line consists of T test cases. First line of every test case consists of N, denoting number of elements is respective arrays. Second and third line consists of arrays containing Inorder and Level-order traversal respectively.

Output:
Single line output, print the preOrder traversal of array.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
1 0 2 
0 1 2 
7
3 1 4 0 5 2 6 
0 1 2 3 4 5 6 
Output:
0 1 2
0 1 3 4 2 5 6

*/
Node *findAns(int inorder[],int levelOrder[],int iStart,int iEnd,int lStart,int lEnd)
{
    if(iStart>iEnd)
        return NULL;
    if(iStart==iEnd)
        return new Node(inorder[iStart]);
    Node *temp=new Node(levelOrder[lStart]);
    int i=iStart;
    for(;i<=iEnd;i++)
    {
        if(inorder[i]==levelOrder[lStart])
            break;
    }
    int si=i-iStart;
    int llOrder[si];
    int lrOrder[iEnd-i];
    int u=0,v=0;
    for(int j=lStart+1;j<=lEnd;j++)
    {
        int c=0;
        for(int k=iStart;k<i;k++)
        {
            if(inorder[k]==levelOrder[j])
            {
                c=1;
                llOrder[u++]=levelOrder[j];
                break;
            }
        }
        if(c==0)
            lrOrder[v++]=levelOrder[j];
    }
    temp->left=findAns(inorder,llOrder,iStart,i-1,0,u-1);
    temp->right=findAns(inorder,lrOrder,i+1,iEnd,0,v-1);
    return temp;
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    //add code here.
    // first node in level order is root
    return findAns(inorder,levelOrder,iStart,iEnd,iStart,iEnd);
}
