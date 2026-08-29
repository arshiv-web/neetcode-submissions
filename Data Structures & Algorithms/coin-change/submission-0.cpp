class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<pair<int, int>>> grid(coins.size(), vector<pair<int, int>>(amount+1, {0, 0}));

        for(int i = 0; i < coins.size(); i++) {
            grid[i][0] = {1, 0};
        }

        for(int j = 1; j <= amount; j++) {
            if(j - coins[0] >= 0 && grid[0][j-coins[0]].first == 1) {
                grid[0][j] = {1, 1 + grid[0][j-coins[0]].second};
            }
        }

        for(int i = 1; i < coins.size(); i++) {
            for(int j = 1; j <= amount; j++) {
                //dont take
                grid[i][j] = grid[i-1][j];
                //take
                if(j - coins[i] >= 0 && grid[i][j - coins[i]].first == 1) {
                    if(grid[i][j].first == 0) {
                        grid[i][j] = {1, 1 + grid[i][j - coins[i]].second};
                    } else {
                        grid[i][j] = {1, min(grid[i][j].second, 1 + grid[i][j - coins[i]].second)};
                    }
                }
                
            }
        }


        return grid[coins.size()-1][amount].first == 1 ? grid[coins.size()-1][amount].second : -1;
    }
};
