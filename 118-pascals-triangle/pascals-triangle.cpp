class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        int l=1;
        for(int i=0;i<numRows;i++) {
            ans[i].resize(i+1);
        }
        for(int i=0;i<numRows;i++){
            for(int j=0;j<l;j++){
                if(j==l-1||j==0)
                ans[i][j]=1;

                else if(i>1){
                    ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
                }
            }
            l++;
        }

        return ans;
    }
};