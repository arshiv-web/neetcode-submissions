class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> psum(nums.size(), 0);
        psum[0] = nums[0];
        int ans{INT_MAX};
        //0, 1, 2, 3, 4,  5
        //2, 5, 6, 8, 12, 15
        for(int i = 1; i < nums.size(); i++){
            psum[i] = nums[i] + psum[i-1];
        }

        for(int i = 0; i < nums.size(); i++){
            if(psum[i] >= target){
                ans = min(ans, i + 1);
            }
        }

        int i{0};
        for(int j = 0; j < nums.size(); j++){
            if(psum[j] - psum[i] < target){
                continue;
            }
            while(psum[j] - psum[i] >= target){
                ans = min(ans, j-i);
                i++;
            }
        }
    
        return ans == INT_MAX ? 0 : ans;
    }
};