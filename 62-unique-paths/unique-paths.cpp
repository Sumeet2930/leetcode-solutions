class Solution {
public:
    int ans(int i, int j, vector<vector<int>>& dp){
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int up = ans(i -1, j, dp);
        int left = ans(i, j - 1, dp);

        return dp[i][j] = up + left ;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m ,vector<int>(n, -1));
        return ans(m - 1, n - 1, dp);
    }
};