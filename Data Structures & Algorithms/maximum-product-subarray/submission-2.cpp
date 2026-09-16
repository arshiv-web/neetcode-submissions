class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxHere = nums[0];
        int minHere = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int prevMax = maxHere;
            int prevMin = minHere;

            maxHere = max({
                nums[i],
                nums[i] * prevMax,
                nums[i] * prevMin
            });

            minHere = min({
                nums[i],
                nums[i] * prevMax,
                nums[i] * prevMin
            });

            ans = max(ans, maxHere);
        }

        return ans;
    }
};