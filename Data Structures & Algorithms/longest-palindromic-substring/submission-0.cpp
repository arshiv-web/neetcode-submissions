class Solution {
public:

    void check(string &s, int &bl, int &bs, int i, int j){
        int l = i;
        int r = j;
        while(l >= 0 && j < s.size()){
            if(s[l] == s[r]){
                if(r - l + 1 > bl){
                    bl = r - l + 1;
                    bs = l;
                }
                l--;
                r++;
            } else{
                return;
            }
        }
    }

    string longestPalindrome(string s) {
        int bl = INT_MIN;
        int bs = -1;

        for(int i{0}; auto &x: s){
            check(s, bl, bs, i, i);
            check(s, bl, bs, i, i + 1);
            i++;
        }

        return s.substr(bs, bl);
    }
};
