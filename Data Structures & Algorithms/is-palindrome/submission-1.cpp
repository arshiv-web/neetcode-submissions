class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        if(i < j){
            return isPalindrome(s, i+1, j-1) && s[i] == s[j];
        } else if(i >= j){
            return true;
        }
    }


    bool isPalindrome(string s) {
        string temp = "";
        for(auto &x: s){
            if(isalnum(x)){
                temp += (isalpha(x) ? tolower(x): x);
            }
        }
        return isPalindrome(temp, 0, temp.size()-1);
    }
};
