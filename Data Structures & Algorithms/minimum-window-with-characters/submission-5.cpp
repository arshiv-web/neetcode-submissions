class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        unordered_map<char, int> cand;
        for(int i = 0; i < t.size(); i++){
            target[t[i]]++;
        }

        int i = 0;
        int j = 0;
        int required = target.size();
        set<pair<int, string>> ans;
        int correct = 0;

        int bl = INT_MAX;
        int bs;

        for(; j < s.size(); j++){
            int len = j - i + 1;
            cand[s[j]]++;
            if(target.count(s[j]) && cand[s[j]] == target[s[j]]){
                correct++;
            }
            while(correct == required){
                int cl = j - i + 1;
                if(cl < bl) {
                    bl = cl;
                    bs = i;
                }
                cand[s[i]]--;
                if(target.count(s[i]) && cand[s[i]] < target[s[i]]){
                    correct--;
                }
                i++;
                
            }
        }
        return bl == INT_MAX ? "" : s.substr(bs, bl);
    }
    
};
