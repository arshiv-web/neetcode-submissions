class Solution {
public:
    int run(vector<int> &nums, int target, int idx){
        if(idx == nums.size()){
            return target == 0;
        }
        return run(nums, target - nums[idx], idx + 1) + run(nums, target + nums[idx], idx + 1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> dp(nums.size() + 1);
        int maxa = accumulate(nums.begin(), nums.end(), 0);
        int mina = -maxa;
        dp[nums.size()][0] = 1;
        for(int i = nums.size() - 1; i >=0; i--){
            for(int j = mina; j <= maxa; j++){
                dp[i][j] = dp[i+1][j - nums[i]] + dp[i+1][j + nums[i]];
            }
        }
        
        return dp[0][target];
    }
};
