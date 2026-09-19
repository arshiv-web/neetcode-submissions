class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> mp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for(int i{0}; auto &x: mp){
            for(int j{0}; auto &y: x){
                if(i!=0 && j!=0 && text1[i-1] == text2[j-1]){
                    y = 1 + mp[i-1][j-1];
                } else {
                    int op1 = (i != 0) ? mp[i-1][j] : 0;
                    int op2 = (j != 0) ? mp[i][j-1]: 0;
                    y = max(op1, op2);
                }
                j++;
            }
            i++;
        }
        return mp.back().back();
    }
};
