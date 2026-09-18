class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        vector<pair<int, int>> s;
        map<int, int> mp;

        for(int i = 0; i < hand.size(); i++){
            mp[hand[i]]++;
        }

        for(auto &x: mp){
            s.push_back({x.first, x.second});
        }

        if(hand.size() % groupSize != 0) return false;

        int groupCount = hand.size() / groupSize;
        int groups = 0;
        int i = 0;
        while(groups < groupCount){
            vector<int> group;
            for(; i < s.size(); i++){
                if(s[i].second == 0){
                    continue;
                } else {
                    break;
                }
            }

            for(int k = i; k < s.size(); k++){
                if(s[k].second == 0) continue;
                if(group.size() == 0 || (s[k].first - group.back() == 1)) {
                    group.push_back(s[k].first);
                    s[k].second--;
                    // cout << "GSIZE" << group.size() << endl;
                    if(group.size() == groupSize) {
                        break;
                    }
                }   
                else {
                    return false;
                }
            }
            if(group.size() != groupSize) return false;
            groups++;
        }
        return true;
    }
};
