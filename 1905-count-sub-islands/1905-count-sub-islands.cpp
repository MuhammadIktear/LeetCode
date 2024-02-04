#include <functional>
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        vector<vector<bool>>vst(n,vector<bool>(m,false));
        vector<pair<int,int>>p={{-1,0},{1,0},{0,-1},{0,1}};
        auto valid=[&](int i,int j)
        {
            return i>=0&&i<n&&j>=0&&j<m&&grid2[i][j]==1;
        };
        bool f;
        function<void(int, int)> dfs=[&](int sr,int sc)
        {
            if(grid1[sr][sc]==0)f=false;
            vst[sr][sc]=true;
            for(int i=0;i<4;i++)
            {
                int cr=sr+p[i].first;
                int cc=sc+p[i].second;
            if(valid(cr,cc)&&!vst[cr][cc])
            {
                dfs(cr,cc);
            }
                
            }
        };
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vst[i][j]&&grid2[i][j] == 1)
                {
                    f=true;
                    dfs(i,j);
                    if(f==true)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};