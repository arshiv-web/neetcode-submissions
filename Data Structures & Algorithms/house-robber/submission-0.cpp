class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 
        int p2 = nums[0];
        int p1 = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            int temp = p1;
            p1 = max(p1, p2 + nums[i]);
            p2 = temp;
        }
        return p1;
    }
};
