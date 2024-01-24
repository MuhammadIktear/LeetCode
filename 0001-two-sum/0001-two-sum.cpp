class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>vp;
        for(int i=0;i<nums.size();i++)
        {
            vp.push_back({nums[i],i});
        }
        sort(vp.begin(),vp.end());
        vector<int>result;
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            int currentSum=vp[left].first+vp[right].first;
            if (currentSum == target) {
            result.push_back(vp[left].second);
            result.push_back(vp[right].second);
            left=nums.size()-1;
        } else if (currentSum < target) {
            ++left;
        } else {
            --right;
        }           
        }
        return result;
    }
};