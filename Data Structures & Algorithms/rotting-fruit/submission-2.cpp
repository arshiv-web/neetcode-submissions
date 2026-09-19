class Solution {
public:
    void process(int i, int j, vector<vector<int>>& grid, queue<pair<int, int>> &q){
        if(i >=0 && i < grid.size()){
            if(j >=0 && j < grid[0].size()){
                if(grid[i][j] == 1){
                    grid[i][j] = 2;
                    q.push({i, j});
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int, int>> q;
        for(int i{0}; auto &x: grid){
            for(int j{0}; auto &y: x){
                if(y == 2){
                    q.push({i, j});
                }
                j++;
            }
            i++;
        }

        while(!q.empty()){
            int qline = q.size();
            for(int i{0}; i < qline; i++){
                pair<int, int> cand  = q.front();
                q.pop();
                process(cand.first + 1, cand.second, grid, q);
                process(cand.first - 1, cand.second, grid, q);
                process(cand.first, cand.second + 1, grid, q);
                process(cand.first, cand.second - 1, grid, q);
            }
            if(!q.empty())
                ans++;
        }

        for(auto &x: grid){
            for(auto &y: x){
                if(y == 1) return -1;
            }
        }

        return ans;   
    }
};
