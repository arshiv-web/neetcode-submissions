class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') {
                st.push('(');
            } else {
                if(st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }

    void run(int n, string curr, vector<string> &ans, int open, int close){
        if(curr.size() == n){
            // if(isValid(curr)){
                ans.push_back(curr);
                return;
            // }
            // return;
        }
        if(open < n/2)
            run(n, curr + "(", ans, open + 1, close);
        if(close < open)
            run(n, curr + ")", ans, open, close + 1);
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        run(2*n, "", ans, 0, 0);
        return ans;
    }
};
