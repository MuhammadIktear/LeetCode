class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string, int> mp;
        vector<vector<string>> ans;
        if(n==0) return ans;
        vector<pair<string, string>> vp(n);

        for (int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            vp[i] = {temp, strs[i]};
            mp[temp]++;
        }

        sort(vp.begin(), vp.end());
        for (auto u : mp) {
            vector<string> v;
            for (int i = 0; i < u.second; i++) {
                v.push_back(vp[i].second);
            }
            ans.push_back(v);
            vp.erase(vp.begin(), vp.begin() + u.second);
        }
        return ans;
    }
};
