class Solution {
public:
    static bool mpc(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> sq = queries;
        sort(sq.begin(), sq.end());
        sort(intervals.begin(), intervals.end(), mpc);
        map<int, int> mp;
        int j = 0;
        set<pair<int, int>> dist_r;

        for(int i = 0; i < sq.size(); i++) {
            int q = sq[i];
            if(mp.count(q)) continue;
            mp[q] = -1;
            while(j < intervals.size() && intervals[j][0] <= q) {
                dist_r.insert({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
                j++;
            }

            while(!dist_r.empty()) {
                auto it = dist_r.begin();
                if(it->second < q) {
                    dist_r.erase(it);
                } else {
                    mp[q] = it->first;
                    break;
                }
            }
        }

        vector<int> ans(queries.size());
        for(int i = 0; i<queries.size(); i++) {
            ans[i] = mp[queries[i]];
        }
        return ans;
    }
};
