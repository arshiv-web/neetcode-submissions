class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> count;
        for(auto &x: nums){
            count.insert(x);
        }
        return count.size() != nums.size();
    }
};