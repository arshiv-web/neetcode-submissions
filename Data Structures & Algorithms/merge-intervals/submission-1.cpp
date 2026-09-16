class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans(1, vector<int>(2));
        ans[0][0] = intervals[0][0];
        ans[0][1] = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= ans[ans.size()-1][1]) {
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            } 
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
