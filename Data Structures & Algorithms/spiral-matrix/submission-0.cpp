class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        
        vector<int> res;
        
        while(res.size() < matrix.size() * matrix[0].size()){
            for(int j = left; j <= right; j++){
                res.push_back(matrix[top][j]);
            }
            top++;
            if(res.size() == matrix.size() * matrix[0].size()) break;

            for(int j = top; j <= bottom; j++){
                res.push_back(matrix[j][right]);
            }
            right--;
            if(res.size() == matrix.size() * matrix[0].size()) break;

            for(int j = right; j >= left; j--){
                res.push_back(matrix[bottom][j]);
            }
            bottom--;
            if(res.size() == matrix.size() * matrix[0].size()) break;

            for(int j = bottom; j >= top; j--){
                res.push_back(matrix[j][left]);
            }
            left++;
            if(res.size() == matrix.size() * matrix[0].size()) break;
        }
        return res;
    }
};