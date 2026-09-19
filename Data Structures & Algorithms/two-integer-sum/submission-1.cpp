class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        for(int i{0}; auto &x: nums){
            mp[x] = i++;
        } 
        for(int i{0}; auto &x: nums){
            if(mp.count(target - x) && i < mp[target-x]){
                return {i, mp[target-x]};
            }
            i++;
        }
        return {-1, -1};
    }
};
