using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        vector<vector<int>> dis(n, vector<int>(n, -1));

        auto isValid = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0;
        };
        if(n==1&&grid[n-1][n-1]==0)return 1;
        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        dis[0][0] = 1;
        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            for (auto dir : directions) {
                int crow = current.first + dir.first;
                int ccol = current.second + dir.second;

                if (isValid(crow, ccol) && dis[crow][ccol] == -1) {
                    dis[crow][ccol] = dis[current.first][current.second] + 1;
                    q.push({crow, ccol});

                    if (crow == n-1 && ccol == n-1) {
                        return dis[crow][ccol];
                    }
                }
            }
        }

        return -1;
    }
};