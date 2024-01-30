class Solution {
public:
    int mod = 1e9 + 7;

    int helper(int i, int j,int k,int m,int n,vector<vector<vector<int>>> &dp){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return 1;
        }
        if(k == 0){
            return 0;
        }

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        int ans = 0;
        ans += helper(i + 1,j,k - 1,m,n,dp) % mod;
        ans %= mod;
        ans += helper(i - 1,j,k - 1,m,n,dp) % mod;
        ans %= mod;
        ans += helper(i,j + 1,k - 1,m,n,dp) % mod;
        ans %= mod;
        ans += helper(i,j - 1,k - 1,m,n,dp) % mod;
        ans %= mod;

        return dp[i][j][k] = ans;
        
    }

    int findPaths(int m, int n, int k, int i, int j) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k + 1,-1)));
        return helper(i,j,k,m,n,dp);
    }
};