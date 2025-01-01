class Solution {
int ans(vector<int>& nums,int i,vector<int>& dp) {
     if (i >= nums.size() - 1) return 0; 
     if(dp[i]!=-1)return dp[i];
      int mini = INT_MAX / 2;
     for(int j=1;j<=nums[i];j++){
        mini=min(mini,1+ans(nums,i+j,dp));
     }
     return dp[i]=mini;
}
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return ans(nums,0,dp);
    }
};