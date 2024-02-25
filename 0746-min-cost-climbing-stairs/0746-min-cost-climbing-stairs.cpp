class Solution {
public:
    int minimumCost(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size())
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        int op1 = minimumCost(cost, i + 1, dp) + cost[i];
        int op2 = minimumCost(cost, i + 2, dp) + cost[i];
        
        dp[i] = min(op1, op2);
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        cost.insert(cost.begin(),0);
        int n = cost.size();
        vector<int> dp(n, -1);
        return minimumCost(cost, 0, dp);
    }
};