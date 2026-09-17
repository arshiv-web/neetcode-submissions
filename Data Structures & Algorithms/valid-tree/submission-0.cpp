class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>> &adj,  vector<int> &visit){
        visit[node] = 1;
        for(int i = 0; i < adj[node].size(); i++){
            if(visit[adj[node][i]] == -1){
                if(!dfs(adj[node][i], node, adj, visit))
                    return false;
            } else if(adj[node][i] != parent){
                return false;
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> visit(n, -1);
        bool noCycle = dfs(0,-1, adj, visit);
        bool flag = true;
        for(int i = 0; i<visit.size(); i++){
            if(visit[i] == -1) {
                flag = false;
                break;
            }
        }
        return flag && noCycle;
    }
};
