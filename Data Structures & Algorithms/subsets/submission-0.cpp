class Solution {
public:

    void run(int x, vector<int>& nums, vector<vector<int>> &res, vector<int> temp){
        if(x == nums.size()){
            res.push_back(temp);
            return;
        }
        run(x+1, nums, res, temp);
        temp.push_back(nums[x]);
        run(x+1, nums, res, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        run(0, nums, res, {});
        return res;
    }
};
