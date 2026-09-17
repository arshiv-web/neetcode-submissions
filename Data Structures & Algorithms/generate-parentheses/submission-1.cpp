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

    void run(int n, string curr, vector<string> &ans){
        if(curr.size() == n){
            if(isValid(curr)){
                ans.push_back(curr);
                return;
            }
            return;
        }
        run(n, curr + "(", ans);
        run(n, curr + ")", ans);
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        run(2*n, "", ans);
        return ans;
    }
};
