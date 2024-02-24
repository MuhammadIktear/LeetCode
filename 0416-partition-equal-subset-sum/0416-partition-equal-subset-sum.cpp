class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto u : nums) sum += u;
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

      
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

       
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};
