class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    break;
                }
            }
            if(!q.empty()) break;
        }
        
        int perimeter = 0;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            
            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                
                if(nr<0 || nr>=n || nc<0 || nc>=m || grid[nr][nc]==0){
                    perimeter++;
                }
                else if(!vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        
        return perimeter;
    }
};