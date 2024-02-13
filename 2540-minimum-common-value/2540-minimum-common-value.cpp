class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;

        for (int i = 0; i < nums1.size(); i++) {
            s1.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++) {
            s2.insert(nums2[i]);
        }

        vector<int> v;

        for (auto u : s1) {
            v.push_back(u);
        }

        for (auto u : s2) {
            v.push_back(u);
        }

        map<int, int> mp;
        int x = -1;

        for (int i = 0; i < v.size(); i++) {
            mp[v[i]]++;
            if (mp[v[i]] == 2) {
                x = v[i];
                break;
            }
        }

        return x;
    }
};
