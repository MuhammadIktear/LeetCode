#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vst(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vst[i][j] = 2;
                } else
                    vst[i][j]=0;
                
            }
        }

        int tm = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + p[i].first;
                int ncol = c + p[i].second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vst[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vst[nrow][ncol] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vst[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return tm;
    }
};