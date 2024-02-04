#include <functional> 
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vst(n, vector<bool>(m, false));
        vector<int> max_area;

        auto valid = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1;
        };

        vector<pair<int, int>> direction = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        function<void(pair<int, int>, int&)> dfs = [&](pair<int, int> p, int& area) {
            area++;
            vst[p.first][p.second] = true;
            for (int i = 0; i < 4; i++) {
                int cr = p.first + direction[i].first;
                int cc = p.second + direction[i].second;
                if (valid(cr, cc) && !vst[cr][cc]) {
                    vst[cr][cc] = true;
                    dfs({cr, cc}, area);
                }
            }
        };

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vst[i][j] && grid[i][j] == 1) {
                    int area = 0;
                    dfs({i, j}, area);
                    max_area.push_back(area);
                    cnt++;
                }
            }
        }

        if (max_area.empty()) {
            return 0;
        }

        auto maxarea = max_element(max_area.begin(), max_area.end());
        return *maxarea;
    }
};
