class Solution {
public:
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,int k,vector<vector<char>> &board, string word){
        if(k==word.size()-1){
            return true;
        }
        char t=board[i][j];
        board[i][j]='0';
        for(auto m:dir){
            int ni=i+m[0];
            int nj=j+m[1];
            if(ni>=0 && nj>=0 && ni<board.size() && nj<board[0].size()){
                if(board[ni][nj]!='0' && word[k+1]==board[ni][nj]){
                    if(check(ni,nj,k+1,board,word)){
                        return true;
                    }
                }
            }
        }
        board[i][j]=t;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(word[0]==board[i][j]){
                    if(check(i,j,0,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};