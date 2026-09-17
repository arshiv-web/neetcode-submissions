class Solution {
public:
    void dfs(int sr, int sc, vector<vector<char>>& grid, vector<vector<int>> &visit) {
        visit[sr][sc] = 1;
        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};
        for(int i = 0; i < dr.size(); i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size()){
                if(grid[nr][nc] == '1' && visit[nr][nc] == 0){
                    dfs(nr, nc, grid, visit);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && visit[i][j] == 0){
                    dfs(i, j, grid, visit);
                    count++;
                }
            }
        }
        return count;
    }
};
