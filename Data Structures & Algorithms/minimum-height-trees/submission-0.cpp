class Solution {
public:

    void dfs(vector<int> &visit, vector<vector<int>> &adj, int src, int call) {
        if(visit[src] != -1) return;
        visit[src] = call;
        for(int i = 0; i < adj[src].size(); i++) {
            if(visit[adj[src][i]] == -1) {
                dfs(visit, adj, adj[src][i], call+1);
            }
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> res(adj.size());
        vector<int> ans;
        for(int i = 0; i < adj.size(); i++) {
            vector<int> visit(adj.size(), -1);
            dfs(visit, adj, i, 0);
            int depth = visit[0];
            for(int j = 1; j < adj.size(); j++) {
                depth = max(visit[j], depth);
            }
            res[i] = depth;
        }
        int minD = res[0];
        for(int j = 1; j < res.size(); j++) {
            minD = min(res[j], minD);
        }
        for(int j = 0; j < res.size(); j++) {
            if(res[j]==minD) ans.push_back(j);
        }
        
        return ans;
    }
};