class Solution {
public:
    int count(string s, int i, int j) {
        int count = 0;
        int l = i;
        int r = j;
        while(l >= 0 && r < s.size() && s[l]==s[r]) {
            count++;
            l--;
            r++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            ans+=count(s, i, i);
            ans+=count(s, i, i+1);
        }
        return ans;
    }
};
