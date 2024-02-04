class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>vst(n,false);
        vector<int>v[n];
        function<void(int)>dfs=[&](int src)
        {
            vst[src]=true;
            for(auto child:v[src])
            {
                if(!vst[child])
                {
                    vst[child]=true;
                    dfs(child);
                }
            }
        };
        for(auto u:edges)
        {
            v[u[0]].push_back(u[1]);
            v[u[1]].push_back(u[0]);
        }
        dfs(source);
        return vst[destination];
    }
};