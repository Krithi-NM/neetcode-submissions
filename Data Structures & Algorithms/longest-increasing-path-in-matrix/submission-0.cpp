class Solution {
public:
    int m, n;
    int delrow[4] = {-1, 1, 0, 0};
    int delcol[4] = {0, 0, -1, 1};
    int dfs(vector<vector<int>>& matrix, int row, int col,
            vector<vector<int>>& dp) {

        if(dp[row][col] != 0)
            return dp[row][col];

        int ans = 1; 

        for(int i = 0; i < 4; i++) {
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            if(newrow >= 0 && newrow < m && newcol >= 0 && newcol < n) {
                if(matrix[newrow][newcol] > matrix[row][col]) {
                    ans = max(ans,1 + dfs(matrix, newrow, newcol, dp));
                }
            }
        }

        return dp[row][col] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int result = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                result = max(result, dfs(matrix, row, col, dp));
            }
        }
        return result;
    }
};