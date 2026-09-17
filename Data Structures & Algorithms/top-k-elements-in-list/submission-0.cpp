class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        set<pair<int, int>> st; //{freq, val}
        unordered_map<int, int> mp;
        for(auto &x: nums){
            mp[x]++;
        }
        for(auto &x: mp){
            st.insert({x.second, x.first});
            if(st.size() > k){
                st.erase(st.begin());
            }
        }
        vector<int> res;
        for(auto &x: st){
            res.push_back(x.second);
        }
        return res;
    }
};
