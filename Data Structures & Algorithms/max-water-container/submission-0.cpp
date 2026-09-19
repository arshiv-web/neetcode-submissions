class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i{0};
        int j{static_cast<int>(heights.size()) - 1};
        int ans{0};

        while(i < j){
            ans = max(ans, (j-i)*min(heights[j], heights[i]));
            if(heights[j] < heights[i]){
                j--;
            } else {
                i++;
            }
        }

        return ans;
    }
};
