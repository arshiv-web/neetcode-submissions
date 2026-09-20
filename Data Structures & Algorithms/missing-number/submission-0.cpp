class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        int sum{accumulate(nums.begin(), nums.end(), 0)};
        return ((n*(n+1)) >> 1) - sum;
    }
};
