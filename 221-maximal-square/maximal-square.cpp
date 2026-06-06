class Solution {
public:
vector<vector<int>>m;
    int check(vector<vector<char>>& matrix,int i,int j){
        if(i>=matrix.size() ||j>=matrix[0].size()){
            return 0;
        }
        if(m[i][j]!=-1){
            return m[i][j];
        }
        int a=check(matrix,i+1,j);
        int b=check(matrix,i+1,j+1);
        int c=check(matrix,i,j+1);
        m[i][j]=0;
        if(matrix[i][j]=='1'){
        m[i][j]= 1+min({a,b,c});
        }
        matrix[i][j]='0';
        return m[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        m=vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),-1));
        check(matrix,0,0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                    ans=max(ans,m[i][j]);
            }
        }
        return ans*ans;
    }
};