class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>winner;
        map<int,int>loser;
        vector<vector<int>>vv;
        vector<int>v1;
        vector<int>v2;
        for(auto u:matches)
        {
            winner[u[0]]++;
            loser[u[1]]++;
        }
        for(auto u:loser)
        {
            if(u.second==1)v1.push_back(u.first);
        }
         for(auto u:winner)
        {
            if(loser.find(u.first)==loser.end())
            {
                v2.push_back(u.first);
            }
        }
        vv.push_back(v2);
        vv.push_back(v1);
        return vv;
    }
};