class Solution {
public:
    int n, m;
    vector<vector<int>> pac;
    vector<vector<int>> atl;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& heights) {
        vis[r][c] = 1;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, vis, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        pac.assign(n, vector<int>(m, 0));
        atl.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            dfs(i, 0, pac, heights);
            dfs(i, m - 1, atl, heights);
        }

        for (int j = 0; j < m; j++) {
            dfs(0, j, pac, heights);
            dfs(n - 1, j, atl, heights);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};