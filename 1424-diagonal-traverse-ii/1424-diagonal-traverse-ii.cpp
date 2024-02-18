class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxSum=0;
        vector<int>ans;
        map<int,vector<int>>mp;
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                maxSum=max(maxSum,i+j);
                {
                    mp[i+j].push_back(nums[i][j]);
                }
            }
        }
        for(int i=0;i<=maxSum;i++)
        {
            for(auto u:mp[i])
            {
                ans.push_back(u);
            }
        }
        return ans;
    }
};