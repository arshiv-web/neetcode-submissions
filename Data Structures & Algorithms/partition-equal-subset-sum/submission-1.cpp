class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2 == 1) return false;
        int target = sum/2;

        vector<vector<bool>> dp(nums.size(), vector<bool>(target+1, false));

        for(int i = 0; i<nums.size(); i++){
            dp[i][0] = true;
        }

        dp[0][nums[0]] = true;

        for(int i = 1; i < nums.size(); i++){
            for(int j = 1; j <= target; j++){
                dp[i][j] = dp[i-1][j] || ( j>=nums[i] ? dp[i-1][j - nums[i]] : dp[i-1][j]);
            }
        }

        return dp.back().back();
    }
};
