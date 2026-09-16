class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2));

        // dp[i][0] = maximum product ending at i
        // dp[i][1] = minimum product ending at i

        dp[0][0] = nums[0];
        dp[0][1] = nums[0];

        int ans = nums[0];

        for(int i = 1; i < n; i++) {
            dp[i][0] = max({
                nums[i],
                nums[i] * dp[i-1][0],
                nums[i] * dp[i-1][1]
            });

            dp[i][1] = min({
                nums[i],
                nums[i] * dp[i-1][0],
                nums[i] * dp[i-1][1]
            });

            ans = max(ans, dp[i][0]);
        }

        return ans;
    }
};