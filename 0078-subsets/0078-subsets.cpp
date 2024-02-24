#include <vector>

class Solution {
    vector<vector<int>> vv;

    void find_subset(vector<int>& nums, vector<int>& v, int i) {
        if (i == nums.size()) {
            vv.push_back(v);
            return;
        }

        v.push_back(nums[i]);
        find_subset(nums, v, i + 1);
        v.pop_back();
        find_subset(nums, v, i + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        find_subset(nums, v, 0);
        return vv;
    }
};
