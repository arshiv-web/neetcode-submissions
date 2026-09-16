class Solution {
public:
    int run(string s, int c, vector<int>&dp) {
        if(c >= s.size()) {
            return 1;
        }
        if(dp[c] != -1) return dp[c];
        int ans = 0;
        if(s[c] == '1') {
            if(c+1 < s.size()) {
                ans += run(s, c+2, dp);
            }
            ans += run(s, c+1, dp);
        } else if (s[c] == '2') {
            if(c+1 < s.size() && s[c+1] <= '6' && s[c+1] >= '0') {
                ans += run(s, c+2, dp);
            }
            ans += run(s, c+1, dp);
        } else if (s[c] == '0') {
            ans = 0;
        } else {
            ans += run(s, c+1, dp);
        }
        return dp[c] = ans;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        run(s, 0, dp);
        return dp[0];
    }
};
