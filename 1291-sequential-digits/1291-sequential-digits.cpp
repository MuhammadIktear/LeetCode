class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            string temp="";
            for(int j=i;j<s.size();j++)
            {
                temp+=s[j];
                int n=stoi(temp);
                if(n>=low&&high>=n)
                {
                    ans.push_back(n);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};