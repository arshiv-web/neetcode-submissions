class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);
        for(auto &x: s){
            freq[x-'a']++;
        }
        for(auto &x: t){
            freq[x-'a']--;
        }
        return vector<int>(26, 0) == freq;
    }
};
