class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>result;
        vector<pair<int,int>>vp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vp.push_back({i+j,mat[i][j]});
            }
        }
        int sz=vp.size();
        int a=vp[sz-1].first;
        for(int i=0;i<=a;i++)
        {
            if(i%2==1){
            vector<int>v;
            for(auto u:vp)
            {
                if(i==u.first)
                {
                    v.push_back(u.second);
                }
            }
            result.insert(result.end(),v.begin(),v.end());
            }
            else 
            {
            vector<int>v;
            for(auto u:vp)
            {
                if(i==u.first)
                {
                    v.push_back(u.second);
                }
            }
            reverse(v.begin(),v.end());
            result.insert(result.end(),v.begin(),v.end());
            }
            }
        
           return result;     
    }
};