class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vst(n, vector<bool>(m, false));
        pair<int, int> p[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        function<bool(int, int)> valid = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m;
        };

        int a = image[sr][sc];

        function<void(int, int)> dfs = [&](int sr, int sc) {
            vst[sr][sc] = true;
            image[sr][sc] = color;
            for (int i = 0; i < 4; i++) {
                int cr = sr + p[i].first;
                int cc = sc + p[i].second;
                if (valid(cr, cc) && !vst[cr][cc] && image[cr][cc] == a) {
                    dfs(cr, cc);
                }
            }
        };

        dfs(sr, sc);
        return image;
    }
};

