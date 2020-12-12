/* This program finds the number of binary search trees possible given all the node values in 
    sorted order. As our input we are only provided with the length of this sequence = n.
    
    A tree is an acyclic graph . A binary tree is a tree where each node has 0, 1 or 2 children. 
    A BST is a binary tree where the left child has value less than root and the right child has value greater than the root.  
    
    We use the dynamic programming approach where our root is varied from 1 to n and all the nodes having 
    value less than root value are put in the left subtree and the nodes having value greater than root value 
    are put in the right subtree. 
    
    Time Complexity - O(n^2)
    Space Complexity - O(n)
    
    Note:- The approach is similar to finding the nth catalan number.
    */

#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli PossibleBST(int n)
{
    lli *Dp=(lli *)malloc((n+1)*sizeof(lli));
    
    Dp[0]=1,Dp[1]=1;                        //Since number of BST's that can be formed for n=0/1 is 1
    
    for(int i=2;i<=n;i++)                   //Calculating possible number of BSTs for all i<=n and storing them for future use-Tabulation Method
    {
        Dp[i]=0;
        for(int j=0;j<i;j++)                
        {
            Dp[i]+=(Dp[j]*Dp[i-j-1]);
        }
    }
    
    lli ans=Dp[n];
    
    free(Dp);
    
    return ans;
}

int main()                                  //Driver function
{
    int n;                                  //Enter length of sequence
    cin>>n;
    cout<<PossibleBST(n)<<endl;
    return 0;
}
/* Sample input:-
        n = 5;
        Output = 42;
        */
