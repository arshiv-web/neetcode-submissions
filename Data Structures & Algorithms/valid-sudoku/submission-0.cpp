class Solution {
public:

    bool rowCheck(int i, vector<vector<char>>& board) {
        vector<int> f(10, 0);
        for(int j = 0; j < 9; j++){
            if(board[i][j] != '.') {
                int x = board[i][j] - '0';
                if(f[x] > 0) {
                    return false;
                }
                f[x]++;
            }
        }
        return true;
    }

    bool colCheck(int i, vector<vector<char>>& board) {
        vector<int> f(10, 0);
        for(int j = 0; j < 9; j++){
            if(board[j][i] != '.') {
                int x = board[j][i] - '0';
                if(f[x] > 0) {
                    return false;
                }
                f[x]++;
            }
        }
        return true;
    }

    bool boxCheck(int i, vector<vector<char>>& board) {
        vector<int> f(10, 0);
        vector<char> h;

        // 0 1 2
        // 3 4 5
        // 6 7 8

        int r = 3 * (i/3);
        int c = 3 * (i%3);

        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                h.push_back(board[r+j][c+k]);
            }
        }

        for(int j = 0; j < h.size(); j++){
            if(h[j] != '.') {
                int x = h[j] - '0';
                if(f[x] > 0) {
                    return false;
                }
                f[x]++;
            }
        }
        return true;
    }    


    bool isValidSudoku(vector<vector<char>>& board) {
        bool check = true;
        for(int i = 0; i<9; i++) {
            check &= rowCheck(i, board) && colCheck(i, board) && boxCheck(i, board);
        }
        return check;
    }
};
