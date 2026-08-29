class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n);
        for(int i = 0; i < times.size(); i++) {
            g[times[i][0] - 1].push_back({times[i][1]-1, times[i][2]});
        }

        vector<int> distance(n, INT_MAX);
        set<pair<int, int>> cs;

        distance[k-1] = 0;
        cs.insert({0, k-1});

        for(int i = 0; i < n; i++) {
            if(i != k-1) {
                cs.insert({INT_MAX, i});
            }
        }

        while(cs.size() > 0) {
            pair<int, int> cand = *cs.begin();
            int cd = cand.first;
            int cn = cand.second;
            if(cd == INT_MAX) break;
            cs.erase({cd, cn});
            for(int i = 0; i<g[cn].size(); i++) {
                int nei = g[cn][i].first;
                int wei = g[cn][i].second;
                if(distance[nei] > cd + wei) {
                    cs.erase({distance[nei], nei});
                    cs.insert({cd + wei, nei});
                    distance[nei] = cd + wei;
                }   
            }
        }
        
        int ans = -1;
        for(int i = 0; i < distance.size(); i++) {
            if(distance[i] == INT_MAX) return -1;
            ans = max(distance[i], ans);
        }
        return ans;
    }
};
