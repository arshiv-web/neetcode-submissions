class Solution {
public:
    int run(int sr, int sc, int prev, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(sr<0 || sr >= matrix.size()) return 0;
        if(sc <0 || sc >= matrix[0].size()) return 0;
        if(matrix[sr][sc] <= prev) return 0;
        if(dp[sr][sc] != -1) return dp[sr][sc]; 
        return dp[sr][sc] = 1 + max(max(
            run(sr+1, sc, matrix[sr][sc], matrix, dp), run(sr-1, sc, matrix[sr][sc], matrix, dp)
        ), max(
            run(sr, sc+1, matrix[sr][sc], matrix, dp), run(sr, sc-1, matrix[sr][sc], matrix, dp)
        ));
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                ans = max(ans, run(i, j, -1, matrix, dp));
            }
        }
        return ans;
    }
};
