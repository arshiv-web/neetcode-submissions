class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mp;

        for(int i = 0; i < s.size(); i++){
            char x = s[i];
            if(mp.count(x)){
                mp[x].second = i;
            } else {
                mp[x] = {i, i};
            }
        }

        vector<int> res;

        int currMin = mp[s[0]].first;
        int currMax = mp[s[0]].second;

        for(int i = 1; i < s.size(); i++){
            if(mp[s[i]].first > currMax){
                //processPrevious
                res.push_back(currMax - currMin + 1);
                currMin = mp[s[i]].first;
                currMax = mp[s[i]].second;
            } else {
                currMax = max(currMax, mp[s[i]].second);
            }
        }
        res.push_back(currMax - currMin + 1);
        return res;
    }
};
// x: 0, 3
// y: 1, 4
// z: 5, 7
// b: 6, 9
// i: 10, 10
// s: 11, 11
// l: 12, 12