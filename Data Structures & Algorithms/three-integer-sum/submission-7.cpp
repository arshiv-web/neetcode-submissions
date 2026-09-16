class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> ans;

        int left = start;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                ans.push_back({nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1])
                    left++;

                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            vector<vector<int>> pairs = twoSum(nums, i + 1, -nums[i]);

            for (auto &p : pairs) {
                ans.push_back({nums[i], p[0], p[1]});
            }
        }

        return ans;
    }
};
