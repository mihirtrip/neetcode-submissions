class Solution {
public:
    int m;
    int n;
    vector<pair<int,int>>dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(int r, int c, vector<vector<char>>& grid){
        grid[r][c] = '#';
        for(auto& [dr,dc]: dir){
            int nr = r+dr;
            int nc = c+dc;

            if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc]!='O'){
                continue;
            }
            dfs(nr,nc,grid);

        }
    }
    void solve(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i =0;i<n;i++){
            if(grid[0][i]=='O'){
                dfs(0,i,grid);
            }
        }
        for(int i =0;i<m;i++){
            if(grid[i][0]=='O'){
                dfs(i,0,grid);
            }
        }
        for(int i =0;i<n;i++){
            if(grid[m-1][i]=='O'){
                dfs(m-1,i,grid);
            }
        }
        for(int i =0;i<m;i++){
            if(grid[i][n-1]=='O'){
                dfs(i,n-1,grid);
            }
        }
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]=='O'){
                    grid[i][j] = 'X';
                }
                else if (grid[i][j]=='#'){
                    grid[i][j] = 'O';
                }
            }
        }
    }
};
