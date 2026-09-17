class Solution {
public:


    //30, 38, 30, 36, 35, 40, 28

    
    
    
    // 38, 1
    // 30, 0

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> res(temperatures.size());
        for(int i = 0; i < temperatures.size(); i++){
            if(st.empty()) {
                st.push({temperatures[i],i});
            } else {
                // if(temperatures[i] <= st.top().first) {
                //     st.push({temperatures[i],i});
                // } else {
                    while(!st.empty() && temperatures[i] > st.top().first) {
                        res[st.top().second] = i - st.top().second;
                        st.pop();
                    }
                    st.push({temperatures[i],i});
                // }
            }
        }

        return res;

    }
};
