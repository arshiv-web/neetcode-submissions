class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n);
        for(int i = 0; i < times.size(); i++) {
            g[times[i][0] - 1].push_back({times[i][1]-1, times[i][2]});
        }
        vector<int> visit(n, 0);
        vector<int> distance(n, -1);
        set<pair<int, int>> cs;

        visit[k-1] = 1;
        distance[k-1] = 0;
        cs.insert({0, k-1});

        while(cs.size() > 0) {
            pair<int, int> cand = *cs.begin();
            int cd = cand.first;
            int cn = cand.second;
            cs.erase({cd, cn});
            for(int i = 0; i<g[cn].size(); i++) {
                int nei = g[cn][i].first;
                int wei = g[cn][i].second;

                if(visit[nei] == 0) {
                    cs.insert({cd + wei, nei});
                    distance[nei] = cd + wei;
                    visit[nei] = 1;
                } else {
                    if(distance[nei] > cd + wei) {
                        cs.erase({distance[nei], nei});
                        cs.insert({cd + wei, nei});
                        distance[nei] = cd + wei;
                    }   
                }
            }
        }
        
        int ans = -1;
        for(int i = 0; i < visit.size(); i++) {
            if(visit[i] == 0) return -1;
            ans = max(distance[i], ans);
        }
        return ans;
    }
};
