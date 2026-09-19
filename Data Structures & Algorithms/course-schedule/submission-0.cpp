class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> idg(numCourses);
        for(auto &edge: prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            idg[edge[0]]++;
        }
        queue<int> q;
        for(int i{0}; auto&x: idg){
            if(x == 0) q.push(i);
            i++;
        }
        int count{0};
        while(!q.empty()){
            int top{q.front()};
            count++;
            q.pop();
            for(auto &nei : graph[top]){
                idg[nei]--;
                if(idg[nei] == 0){
                    q.push(nei);
                }
            }
        }
        return count == numCourses;
    }
};
