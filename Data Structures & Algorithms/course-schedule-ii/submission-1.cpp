class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> idg(numCourses, 0);

        for(int i = 0; i<prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            idg[a]++;
        }

        vector<int> ans;
        vector<int> blank;
        queue<int> q;

        for(int i = 0; i<idg.size(); i++){
            if(idg[i]==0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(int i=0; i<adj[x].size(); i++) {
                idg[adj[x][i]]--;
                if(idg[adj[x][i]] == 0) {
                    q.push(adj[x][i]);
                }
            }
        }

        if(ans.size() == numCourses) return ans;
        return blank;
    }
};
