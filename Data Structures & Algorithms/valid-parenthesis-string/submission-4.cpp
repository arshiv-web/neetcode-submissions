class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> wild;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                open.push(i);
            } 
            if(s[i] == '*') {
                wild.push(i);
            }
            if(s[i] == ')') {
                if(!open.empty()) {
                    open.pop();
                }
                else if(!wild.empty()) {
                    wild.pop();
                } else {
                    return false;
                }
            }
        }
        while(!open.empty() && !wild.empty() && open.top() < wild.top()) {
            open.pop();
            wild.pop();
        }
        return open.empty();
    }
};
