class Solution {
public:
   void check(int i,int j,vector<vector<char>>& board){
    if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!='O'){
        return;
    }
    board[i][j]='1';
    check(i+1,j,board);
    check(i-1,j,board);
    check(i,j+1,board);
    check(i,j-1,board);
   }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i==0||j==0||i==board.size()-1||j==board[0].size()-1){
                    if(board[i][j]=='O'){
                        check(i,j,board);
                    }
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='1'){
                    board[i][j]='O';
                }
            }
        }
    }
};