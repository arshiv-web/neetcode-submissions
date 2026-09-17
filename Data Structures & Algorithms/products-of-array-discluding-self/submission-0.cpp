class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> dp(nums.size());
        vector<int> rdp(nums.size());
        dp[0] = 1;
        for(int i = 1; i<nums.size(); i++) {
            dp[i] = dp[i-1]*nums[i-1]; 
        }

        rdp[nums.size()-1] = 1;
        for(int i = nums.size() - 2; i>=0; i--) {
            rdp[i] = rdp[i+1]*nums[i+1]; 
        }

        vector<int> res(dp.size());

        for(int i = 0; i < dp.size(); i++){
            res[i] = dp[i]*rdp[i]; 
        }
        return res;
    }
};
