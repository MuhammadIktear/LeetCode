class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        for (int j = 0; j < m; ++j) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = matrix[i][j] + dp[i - 1][j]; 

                if (j > 0) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i - 1][j - 1]); 
                }

                if (j < m - 1) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i - 1][j + 1]);  
                }
            }
        }

        int result = INT_MAX;
        for (int j = 0; j < m; ++j) {
            result = min(result, dp[n - 1][j]);
        }

        return result;
    }
};
