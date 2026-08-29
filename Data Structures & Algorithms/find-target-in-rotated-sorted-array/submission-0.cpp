class Solution {
public:
    int find(vector<int>& nums, int target, int l, int r) {
        if(l > r) return -1;
        int mid = l + (r-l)/2;
        if(nums[mid]==target) return mid;
        int targetSection = target >= nums[0] ? 1: 2;
        int midSection = nums[mid] >= nums[0] ? 1: 2;

        if(targetSection > midSection) {
            return find(nums, target, mid + 1, r);
        } else if(targetSection < midSection) {
            return find(nums, target, l, mid - 1);
        } else {
            if(nums[mid] > target) {
                return find(nums, target, l, mid-1);
            } else {
                return find(nums, target, mid+1, r);
            }
        }

    }
    int search(vector<int>& nums, int target) {
        return find(nums, target, 0, nums.size()-1);
    }
};
