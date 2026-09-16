class Solution {
public:

    int find(vector<int> &nums, int i) {
        vector<int> dp(nums.size()-1);
        dp[0] = nums[i];
        dp[1] = max(nums[i], nums[i+1]);

        for(int k = 2; k < nums.size() - 1; k++) {
            dp[k] = max(dp[k-1], dp[k-2] + nums[i+k]);
        }
        return dp[nums.size()-2];
    }


    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        return max(find(nums, 1), find(nums, 0));
    }
};
