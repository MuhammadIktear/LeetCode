class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>v;
        for (int i = 0; i < s.size(); i++) {
            for (int j = s.size() - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    v.push_back(j - i-1);
                }
            }
        }
        if(v.size()>0){
        auto mx=max_element(v.begin(),v.end());
            return *mx;
            }
        return -1;
    }
};