class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &x: nums){
            mp[x]++;
        }
    

        int ans = 0;

        for(auto &x: mp){
            if(!mp.count(x.first - 1)){
                int temp = x.first;
                int cans = 0;
                while(mp.count(temp++)){
                    cans++;
                }
                ans = max(ans, cans);
            }
        }
        return ans;
    }
};
