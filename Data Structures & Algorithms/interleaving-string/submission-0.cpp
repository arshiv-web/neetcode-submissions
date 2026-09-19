class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool>> mp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        for(int i{0}; auto &x: mp){
            for(int j{0}; auto y: x){
                if(i == 0 && i == j){
                    y = true;
                } else {
                    bool op1 = (i!= 0 && s1[i-1] == s3[i - 1 + j]) ? mp[i-1][j]: 0;
                    bool op2 = (j!=0 && s2[j-1] == s3[i + j - 1]) ? mp[i][j-1]: 0;
                    y = op1 || op2;
                }
                j++;
            }
            i++;
        }
        return mp.back().back();
    }
};
