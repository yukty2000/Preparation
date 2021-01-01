/*
Leetcode - Hard

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 

*/

int _X[] = {1, -1, 0, 0} ;
int _Y[] = {0, 0, 1, -1} ;

bool inside(int &i, int &j, int &r, int &c){
    return i >= 0 && j >= 0 && i < r && j < c ;
}

int dfs(int& r, int& c, vector<vector<int>> &matrix, vector<vector<bool>> &vis, vector<vector<int>> &dp, int i, int j){
    if( vis[i][j] ) return dp[i][j] ;
    vis[i][j] = true ;
    int ans = -1 ;
    for(int m = 0 ; m < 4 ; m++){
        int nx = i + _X[m], ny = j + _Y[m] ;
        if( !inside(nx, ny, r, c) ) continue ;
        if( matrix[nx][ny] <= matrix[i][j] ) continue ;
        if( !vis[nx][ny] ) 
            ans = max(ans, dfs(r, c, matrix, vis, dp, nx, ny) ) ;
        else
            ans = max(ans, dp[nx][ny]) ;
    }
    return ( dp[i][j] = ans + 1 );
}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r = matrix.size(); 
        if( r == 0 ) return 0 ;
        int c = matrix[0].size() ;
        vector<vector<bool>> vis(r, vector<bool> (c, false) ) ;
        vector<vector<int>> dp(r, vector<int>(c, 0)) ;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if( !vis[i][j] ){
                    dfs(r, c, matrix, vis, dp, i, j) ;
                }
            }
        }
        int ans = -1 ;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                ans = max(ans, dp[i][j]) ;
            }
        }
        return ans + 1 ;   
    }
};
