class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int cend = 0;
        int farthest = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, nums[i] + i);
            if(i == cend) {
                jumps++;
                cend = farthest;
            }
        }

        return jumps;
    }
};
