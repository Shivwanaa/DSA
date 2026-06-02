class Solution {
public:
vector<vector<int>>m;
    int check(vector<vector<int>>& triangle,int i,int j){
        if(i==triangle.size()){
            return 0;
        }
        if(i>triangle.size()||j>=triangle[i].size()){
            return 1e9;
        }
        if(m[i][j]!=1e9){
            return m[i][j];
        }
        int a=triangle[i][j]+check(triangle,i+1,j+1);
        int b=triangle[i][j]+check(triangle,i+1,j);
        m[i][j]= min(a,b);
        return m[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        m=vector<vector<int>>(n+1,vector<int>(triangle[n-1].size(),1e9));

        return check(triangle,0,0);
    }
};