class Solution {
public:
    int getDistance(vector<int> &a, vector<int> &b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        map<vector<int>, bool> mp;
        set<pair<int, vector<int>>> wv;

        for(int i = 0; i < points.size(); i++) {
            mp[points[i]] = false;
        }

        wv.insert({0, points[0]});

        int ans = 0;
        int visited = 0;
        while(!wv.empty()) {
            auto cand = *wv.begin();
            wv.erase(cand);
            vector<int> cp = cand.second;
            if(mp[cp]) continue;
            mp[cp] = true;
            visited++;
            ans += cand.first;
            if(visited == points.size()) break;
            for(int i = 0; i < points.size(); i++) {
                if(mp[points[i]] == false) {
                    wv.insert({getDistance(cp, points[i]), points[i]});
                }
            } 
        }

        return ans;
    }
};
