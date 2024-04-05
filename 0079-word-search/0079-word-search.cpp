class Solution {
bool search(vector<vector<char>>& board, string &word, int n, int m, int i, int j, int k) {
    if (k == word.size()) return true;
    if (i < 0 || i ==n || j < 0 || j == m || board[i][j] != word[k]) return false;
    char c = board[i][j];
    board[i][j] = '-';
    bool result = (search(board, word, n,m, i + 1, j, k + 1) ||
                   search(board, word, n,m, i - 1, j, k + 1) ||
                   search(board, word, n,m, i, j + 1, k + 1) ||
                   search(board, word, n,m, i, j - 1, k + 1));
    board[i][j] = c;
    return result;
}

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m=board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    bool ans = search(board, word, n, m, i, j, 0);
                    if (ans) return true;
                }
            }
        }
        return false;
    }
};
