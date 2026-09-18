class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        vector<int> rdp(heights.size(), 0);
        vector<int> ldp(heights.size(), 0);

        for(int i = 0; i < heights.size(); i++){
            rdp[i] = heights.size() - i - 1;
            ldp[i] = i;
        }

        st.push({heights[0], 0});
        for(int i = 1; i < heights.size(); i++){
            while(!st.empty() && heights[i] < st.top().first){
                rdp[st.top().second] = i - st.top().second - 1;
                st.pop();
            }
            st.push({heights[i], i});
        }

        
        st.push({heights[heights.size() - 1], heights.size() - 1});
        for(int i = heights.size() - 2; i >= 0; i--){
            while(!st.empty() && heights[i] < st.top().first){
                ldp[st.top().second] = st.top().second - i - 1;
                st.pop();
            }
            st.push({heights[i], i});
        }

        int ans = 0;
        for(int i = 0; i < rdp.size(); i++){
            ans = max(ans, (ldp[i] + rdp[i] + 1) * heights[i]);
        }

        return ans;
    }
};

// 0, 4, 0, 2, 1, 0
// 7, 1, 7, 2, 2, 4