using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dis(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        pair<int, int> moves[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dis[row][col] = steps;

            for (int i = 0; i < 4; i++) {
                int cr = row + moves[i].first;
                int cc = col + moves[i].second;

                if (cr >= 0 && cr < n && cc >= 0 && cc < m && vis[cr][cc] == 0) {
                    vis[cr][cc] = 1;
                    q.push({{cr, cc}, steps + 1});
                }
            }
        }

        return dis;
    }
};

