class Solution {
public:
    bool find(vector<vector<char>>& board, vector<vector<int>>& visit, string word, int i, int j) {

        if(word == "") return true;

        visit[i][j] = 1;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for(int c = 0; c < 4; c++) {
            int gx = dx[c] + i;
            int gy = dy[c] + j;

            if(gx >= 0 && gx < board.size()) {
                if(gy >= 0 && gy < board[0].size()) {
                    if(!visit[gx][gy]) {
                        if(board[gx][gy] == word[0]) {
                            if(find(board, visit, word.substr(1),gx, gy)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        visit[i][j] = 0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        bool check = false;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<int>> visit(board.size(), vector<int>(board[0].size()));
                    // cout << i << ":" << j << endl;
                    check |= find(board, visit, word.substr(1), i, j);
                }
            }
        }
        return check;
    }
};
