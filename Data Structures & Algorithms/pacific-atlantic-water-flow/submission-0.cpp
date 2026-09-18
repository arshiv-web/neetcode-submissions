class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& heights,
             vector<vector<int>>& visit) {

        visit[sr][sc] = 1;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++) {
            int nr = sr + dr[k];
            int nc = sc + dc[k];

            if(nr < 0 || nr >= heights.size() ||
               nc < 0 || nc >= heights[0].size())
                continue;

            if(visit[nr][nc])
                continue;

            // Reverse water flow:
            // ocean -> same/higher elevation
            if(heights[nr][nc] >= heights[sr][sc])
                dfs(nr, nc, heights, visit);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // Pacific: top row + left column
        for(int j = 0; j < n; j++) {
            dfs(0, j, heights, pacific);
        }

        for(int i = 0; i < m; i++) {
            dfs(i, 0, heights, pacific);
        }

        // Atlantic: bottom row + right column
        for(int j = 0; j < n; j++) {
            dfs(m - 1, j, heights, atlantic);
        }

        for(int i = 0; i < m; i++) {
            dfs(i, n - 1, heights, atlantic);
        }

        vector<vector<int>> res;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};