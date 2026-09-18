class Solution {
public:
    void dfs(int i, int j, int id, vector<vector<int>>& grid, int &size) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] != 1) return;
        grid[i][j] = id;
        size++;
        dfs(i+1, j, id, grid, size);
        dfs(i-1, j, id, grid, size);
        dfs(i, j+1, id, grid, size);
        dfs(i, j-1, id, grid, size);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int id = 2;
        int ans = 0;
        for(int i = 0; auto &x: grid){
            for(int j = 0; auto &y: x){
                if(y == 1){
                    int size = 0;
                    dfs(i, j, id, grid, size);
                    ans = max(ans, size);
                    id++;
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};
