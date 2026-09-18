class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        set<string> cities;
        unordered_map<string, int> mp;
        unordered_map<int, string> rev;
        for(int i = 0; i < tickets.size(); i++){
            cities.insert(tickets[i][0]);
            cities.insert(tickets[i][1]);
        }
        int c = 0;
        for(auto &x: cities){
            mp[x] = c;
            rev[c] = x;
            c++;
        }
        vector<multiset<int>> graph(c);
        for(int i = 0; i < tickets.size(); i++){
            graph[mp[tickets[i][0]]].insert(mp[tickets[i][1]]);
        }
        vector<string> ans;

        function<void(int)> dfs = [&](int curr) {
            while(!graph[curr].empty()) {
                int next = *graph[curr].begin();
                graph[curr].erase(graph[curr].begin());

                dfs(next);
            }

            ans.push_back(rev[curr]);
        };

        dfs(mp["JFK"]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
