class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& board) {
        if(i < 0 || i >= board.size()) return;
        if(j < 0 || j >= board[0].size()) return;
        if(board[i][j] != 'O') return;
        board[i][j] = '#';
        dfs(i+1, j, board);
        dfs(i-1, j, board);
        dfs(i, j-1, board);
        dfs(i, j+1, board);
    }

    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(i == 0 || i == board.size()-1 || j ==0 || j == board[0].size()-1){
                    if(board[i][j] == 'O') {
                        dfs(i, j, board);
                    }
                }
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
