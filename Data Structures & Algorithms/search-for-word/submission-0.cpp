class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int i) {

        int m = board.size();
        int n = board[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n)
            return false;

        if (board[r][c] != word[i])
            return false;

        if (i == word.size() - 1)
            return true;

        char temp = board[r][c];
        board[r][c] = '#';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (dfs(board, word, nr, nc, i + 1))
                return true;
        }

        board[r][c] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (board[r][c] == word[0]) {

                    if (dfs(board, word, r, c, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
