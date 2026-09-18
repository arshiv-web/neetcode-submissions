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
        for(int i = 0; i < (1 << nums.size()); i++){
            vector<int> temp{};
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j)) {
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
