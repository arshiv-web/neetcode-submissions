class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &x: tokens){
            if(x == "+" || x == "-" || x == "/" || x == "*"){
                int b{st.top()};
                st.pop();
                int a{st.top()};
                st.pop();
                int c;
                if(x == "+")
                    c = a + b;
                else if(x == "-")
                    c = a - b;
                else if(x == "*")
                    c = a * b;
                else
                    c = a / b;
                st.push(c); 
            } else {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};
