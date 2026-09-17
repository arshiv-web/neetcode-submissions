class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        set<pair<float, vector<int>>, greater<>> dp;

        for(int i = 0; i < points.size(); i++) {
            dp.insert({sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]), points[i]});
            if(dp.size()>k) {
                dp.erase(dp.begin());
            }
        }

        vector<vector<int>> ans;
        for(auto &x: dp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
