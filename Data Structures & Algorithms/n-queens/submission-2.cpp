class Solution {
public:

    bool valid(int x, int y, vector<string> &board) {
        for(int i = 0; i < x; i++) {
            if(board[i][y] == 'Q')
                return false;
        }

        int r = x  - 1;
        int c = y - 1;
        while(r >=0 && c >= 0) {
            if(board[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }

        r = x  - 1;
        c = y + 1;
        while(r >=0 && c < board.size()) {
            if(board[r][c] == 'Q') {
                return false;
            }
            r--;
            c++;
        }
        return true;
    }

    void solve(int row, vector<vector<string>> &ans, vector<string> &board) {
        if(row == board.size()) {
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < board.size(); j++) {
            if(valid(row, j, board)) {
                board[row][j] = 'Q';
                solve(row + 1, ans, board);
                board[row][j] = '.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string temp;
        for(int j = 0; j < n; j++) {
            temp += ".";
        }
        vector<string> board(n, temp);
        solve(0, ans, board);
        return ans;
    }
};
