class Solution {
public:
    bool canJump(vector<int>& nums) {
    int finalPosition = nums.size()- 1;
    for (int idx = nums.size() - 2; idx >= 0; idx--) {
      if (finalPosition-idx<=nums[idx]) {
        finalPosition = idx;
      }
    }
    return finalPosition == 0;
    }
    
};