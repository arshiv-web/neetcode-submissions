class Solution {
public:
    int maxf(map<char, int> &visit) {
        for(auto &x: visit){
            if(x.second > 1) {
                return 0;
            }
        }
        return 1;
    }
    int lengthOfLongestSubstring(string s) {
       int l = 0;
       map<char, int> visit;
       for(char x = 'a'; x <= 'z'; x++){
            visit[x] = 0;
       }
       int ans = 0;
       for(int r = 0; r < s.size(); r ++){
            visit[s[r]]++;
            while(!maxf(visit)){
                visit[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
       }
       return ans;
    }
};
