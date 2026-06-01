class Solution {
public:
vector<vector<int>>m;
    int check(vector<vector<int>>& matrix,int i,int j){
        if(i==matrix.size()){
            return 0;
        }
        if(j>=matrix[0].size()||i<0||j<0){
            return 1e9;
        }
        if(m[i][j]!=-1e9){
            return m[i][j];
        }
        int a=matrix[i][j]+check(matrix,i+1,j);
        int b=matrix[i][j]+check(matrix,i+1,j+1);
        int c=matrix[i][j]+check(matrix,i+1,j-1);
        m[i][j]= min({a,b,c});
        return m[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=1e9;
        m=vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),-1e9));
        for(int i=0;i<matrix[0].size();i++){
            ans=min(ans,check(matrix,0,i));
        }
        return ans;
    }
};