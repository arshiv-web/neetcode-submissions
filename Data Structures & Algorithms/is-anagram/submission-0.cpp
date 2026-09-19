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
        vector<int> model(26, 0);
        return model == freq;
    }
};
