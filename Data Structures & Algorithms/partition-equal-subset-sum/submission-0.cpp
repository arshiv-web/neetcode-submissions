class Solution {
public:
    bool find(vector<int>& nums, int c, int target, int csum) {
        if(csum == target) return true;
        if(c == nums.size()) return false;
        return find(nums, c+1, target, csum+nums[c]) || find(nums, c+1, target, csum);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2 == 1) return false;
        int target = sum/2;
        return find(nums, 0, target, 0);
    }
};
