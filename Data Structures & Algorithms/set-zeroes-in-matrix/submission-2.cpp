class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        //check if last row is bad
        int a = 0;
        int b = 0;

        for(int i = 0; i < matrix[0].size(); i++){
            if(matrix[matrix.size() - 1][i] == 0){
                a = 1;
                break;
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][matrix[0].size() - 1] == 0){
                b = 1;
                break;
            }
        }

        //push 0 to last row and column
        for(int i = 0; i < matrix.size() - 1; i++){
            for(int j = 0; j < matrix[0].size() - 1; j++){
                if(matrix[i][j] == 0){
                    matrix[i][matrix[0].size() - 1] = 0;
                    matrix[matrix.size() - 1][j] = 0;
                }
            }
        }

        //use last row as ref
        for(int i = 0; i < matrix.size() - 1; i++){
            if(matrix[i][matrix[0].size() - 1] == 0){
                for(int j = 0; j < matrix[0].size(); j++){
                    matrix[i][j] = 0;
                }
            }
        }

        //use last column as ref
        for(int i = 0; i < matrix[0].size() - 1; i++){
            if(matrix[matrix.size()-1][i] == 0){
                for(int j = 0; j < matrix.size(); j++){
                    matrix[j][i] = 0;
                }
            }
        }

        //verify last row
        if(a == 1){
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[matrix.size()-1][j] = 0;
            }
        }

        if(b == 1){
            for(int j = 0; j < matrix.size(); j++){
                matrix[j][matrix[0].size()-1] = 0;
            }
        }
    }
};
