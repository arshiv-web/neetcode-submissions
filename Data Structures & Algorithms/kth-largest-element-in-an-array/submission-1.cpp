class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s;
        for(auto &x: nums){
            s.insert(x);
            if(s.size() > k){
                s.erase(s.begin());
            }
        }
        return *s.begin();
    }
};
