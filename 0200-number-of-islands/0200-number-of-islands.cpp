#include <functional>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vst(n, vector<bool>(m, false));

        auto valid = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1';
        };

        vector<pair<int, int>> direction = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        function<void(int, int)> dfs = [&](int i, int j) {
            vst[i][j] = true;
            for (int k = 0; k < 4; k++) {
                int ni = i + direction[k].first;
                int nj = j + direction[k].second;
                if (valid(ni, nj) && !vst[ni][nj]) {
                    dfs(ni, nj);
                }
            }
        };

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vst[i][j] && grid[i][j] == '1') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
