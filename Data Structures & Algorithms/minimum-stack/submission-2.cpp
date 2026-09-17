class MinStack {
private:
    stack<int> st;
    stack<int> ms;
public:

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(ms.empty()){
            ms.push(val);
        } else if(val <= ms.top()){
            ms.push(val);
        }
    }
    
    void pop() {
        int x = st.top();
        st.pop();
        if(!ms.empty() && x == ms.top()){
            ms.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ms.top();
    }
};
