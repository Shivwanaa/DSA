class Solution {
public:
    bool check(vector<vector<char>>& board, string word,int i,int j,int idx){
        if(idx==word.size()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()){
            return false;
        }
        if(board[i][j]!=word[idx]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='*';
        bool ans= check(board,word,i+1,j,idx+1)||check(board,word,i-1,j,idx+1)||check(board,word,i,j+1,idx+1)||check(board,word,i,j-1,idx+1);

        board[i][j]=temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool f=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    if(check(board,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};