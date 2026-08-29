class Solution {
public:

    int findMax(unordered_map<char, int> &freq) {
        int ans = freq['A'];
        for(auto &x: freq){
            ans = max(ans, x.second);
        }
        return ans;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int ans = 0;
        int l = 0;
        for(int r = 0; r < s.size(); r++) {
            int window = r - l + 1;
            freq[s[r]]++;
            if(window - findMax(freq) <= k)
                ans = max(ans, window);
            else {
                freq[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};
