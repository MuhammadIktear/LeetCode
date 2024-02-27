class Solution {
    int f(int i,int j,int n,vector<vector<int>>& triangle, vector<vector<int>>&dp)
    {
        if (dp[i][j] != -1)
        return dp[i][j];

       if (i == n - 1)
        return triangle[i][j];

    int down = triangle[i][j] + f(i + 1, j, n, triangle, dp);
    int diagonal = triangle[i][j] + f(i + 1, j + 1, n, triangle, dp);

    return dp[i][j] = min(down, diagonal);
}

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,n,triangle,dp);
    }
};