class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>  ans;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (1 << nums.size()); i++){
            vector<int> temp;
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j)){
                    temp.push_back(nums[j]);
                }
                ans.insert(temp);
            }
        }

        for(auto &x: ans){
            res.push_back(x);
        }
        return res;
    }
};
