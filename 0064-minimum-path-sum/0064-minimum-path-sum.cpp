class Solution {
    int f(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (m == 0 && n == 0) return grid[m][n];
        if (m < 0 || n < 0) return INT_MAX;
        if (dp[m][n] != -1) return dp[m][n];
        
        int up = f(m - 1, n, dp, grid);
        int left = f(m, n - 1, dp, grid);

        int result = grid[m][n] + min(up, left);

        return dp[m][n] = result;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp, grid);
    }
};
