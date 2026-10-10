class Solution {
public:
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i,int j,string& word,int idx,vector<vector<char>>& board){
        if(idx==word.size()-1){
            return true;
        }
        char t=board[i][j];
        board[i][j]='0';
        for(auto k:dir){
            if(k[0]+i<0||k[0]+i>=board.size()||k[1]+j<0||k[1]+j>=board[0].size()){
                continue;
            }
            if(word[idx+1]==board[k[0]+i][k[1]+j]){
                if(check(i+k[0],j+k[1],word,idx+1,board)){
                    return true;
                }
            }
        }
        board[i][j]=t;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(check(i,j,word,0,board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};