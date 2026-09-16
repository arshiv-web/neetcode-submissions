class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int a = newInterval[0];
        int b = newInterval[1];

        for(int i = 0; i < intervals.size(); i++) {
            int ca = intervals[i][0];
            int cb = intervals[i][1];

            // Completely before newInterval
            if(cb < a) {
                ans.push_back(intervals[i]);
            }

            // Completely after newInterval
            else if(ca > b) {
                ans.push_back({a, b});

                // Everything after this is also after newInterval
                for(int j = i; j < intervals.size(); j++) {
                    ans.push_back(intervals[j]);
                }

                return ans;
            }

            // Overlapping
            else {
                a = min(a, ca);
                b = max(b, cb);
            }
        }

        // newInterval goes at the end
        ans.push_back({a, b});

        return ans;
    }
};