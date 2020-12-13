/*
Leetcode Problem-
Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone
from the row and receive points equal to the sum of the remaining stones' values in the row. 
The winner is the one with the higher score when there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. 
Alice's goal is to maximize the difference in the score.

Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in
Alice and Bob's score if they both play optimally.
*/
typedef long long int lli;
class Solution {
public:
    int findans(int *sum_arr,vector<int> stones)
    {
    int n=stones.size();
    int **dp=(int **)calloc(n,sizeof(int *));
    for(int i=0;i<n;i++)
    {
        dp[i]=(int *)calloc(n,sizeof(int));
    }
    for(int i=0;i<n;i++)
        dp[i][i]=0;
    for(int i=0;i<=n-2;i++)
    {
        dp[i][i+1]=max(stones[i],stones[i+1]);
    }

    for(int d=2;d<n;d++)
    {
        for(int i=0;i<n-d;i++)
        {
            int j=i+d;
            int ans;
            int rangesum1,rangesum2;
            if(i-1>=0)
                rangesum1=sum_arr[j-1]-sum_arr[i-1];
            else
                rangesum1=sum_arr[j-1];
            rangesum2=sum_arr[j]-sum_arr[i];
            int diff1=rangesum1-dp[i][j-1];
            int diff2=rangesum2-dp[i+1][j];
            dp[i][j]=max(diff1,diff2);
        }
    }
    /*cout<<"DP"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"Pos"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<pos[i][j]<<"\t";
        cout<<endl;
    }*/
    int ans=dp[0][n-1];
    for(int i=0;i<n;i++)
    {
        free(dp[i]);
    }
    free(dp);
    return ans;

}
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        int *sum_arr=(int *)calloc(n,sizeof(int));
        sum_arr[0]=stones[0];
        for(int i=1;i<n;i++)
            sum_arr[i]=sum_arr[i-1]+stones[i];
        int ans=findans(sum_arr,stones);
        free(sum_arr);
        return ans;
        
    }
};

 
