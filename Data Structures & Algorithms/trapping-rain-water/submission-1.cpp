class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> ldp(height.size());
        vector<int> rdp(height.size());

        ldp[0] = 0;
        for(int i = 1; i < ldp.size(); i++){
            ldp[i] = max(ldp[i-1], height[i-1]);
        }

        rdp[height.size() - 1] = 0;
        for(int i = height.size() - 2; i >= 0; i--){
            rdp[i] = max(rdp[i+1], height[i+1]);
        }

        int ans = 0;
        for(int i = 0; i<height.size(); i++){
            ans += max(0, min(ldp[i], rdp[i]) - height[i]);
        }
        return ans;
    }
};
