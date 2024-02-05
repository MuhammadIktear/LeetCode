class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pathdistance(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        pair<int, int> p[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        pathdistance[0][0] = 0;
        q.push({0, {0, 0}});

        while (!q.empty()) {
            auto par = q.top();
            q.pop();
            int diff = par.first;
            int cr = par.second.first;
            int ci = par.second.second;

            if (cr == n - 1 && ci == m - 1) {
                return diff;
            }

            for (int i = 0; i < 4; i++) {
                int newr = cr + p[i].first;
                int newcol = ci + p[i].second;

                if (newr >= 0 && newr < n && newcol >= 0 && newcol < m) {
                    int newEffort = max(abs(heights[cr][ci] - heights[newr][newcol]), diff);

                    if (newEffort < pathdistance[newr][newcol]) {
                        pathdistance[newr][newcol] = newEffort;
                        q.push({newEffort, {newr, newcol}});
                    }
                }
            }
        }
        return 0;
    }
};