class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9],cols[9], box[9];
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.'){
                    continue;
                }
                int bid=(i/3)*3+(j/3);
                if(rows[i].count(board[i][j])){
                    return false;
                }
                if(cols[j].count(board[i][j])){
                    return false;
                }
                if(box[bid].count(board[i][j])){
                    return false;
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                box[bid].insert(board[i][j]);
            }
        }
        return true;
    }
};