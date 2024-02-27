class Solution {
    int f(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (m == 0 && n == 0) return (grid[m][n] == 0) ? 1 : 0;
        if (m < 0 || n < 0 || grid[m][n] == 1) return 0;
        if (dp[m][n] != -1) return dp[m][n];

        int left = 0, right = 0;

        if (m > 0 && grid[m - 1][n] != 1) {
            left = f(m - 1, n, dp, grid);
        }

        if (n > 0 && grid[m][n - 1] != 1) {
            right = f(m, n - 1, dp, grid);
        }

        return dp[m][n] = left + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp, grid);
    }
};
