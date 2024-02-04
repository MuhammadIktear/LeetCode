class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vst(n, vector<bool>(m, false));

        auto valid = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1;
        };

        vector<pair<int, int>> p = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        queue<pair<int,int>> q;
        int sr, sc;
        int perimeter = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                    break;
                }
            }
        }

        q.push({sr, sc});
        vst[sr][sc] = true;

        while(!q.empty()) {
            pair<int,int> par = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int cr = par.first + p[i].first;
                int cc = par.second + p[i].second;

                if(valid(cr, cc) && !vst[cr][cc]) {
                    vst[cr][cc] = true;
                    q.push({cr, cc});
                } else if(!valid(cr, cc)) {
                    perimeter++;
                }
            }
        }

        return perimeter;
    }
};