class Solution {
public:
    int change(int value, vector<int>& coin) {
    int n=coin.size();
    int dp[n+1][value+1];
    dp[0][0]=1;
    for(int i=1;i<=value;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=value;j++)
        {
            if(coin[i-1]<=j)
            {
                dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][value];   
    }
};