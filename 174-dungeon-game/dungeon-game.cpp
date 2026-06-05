class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows=dungeon.size();
        int cols=dungeon[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,INT_MAX));
        auto getmin=[&](int curr,int nr,int nc)->int{
            if(nr>=rows ||nc>=cols){
                return INT_MAX;
            }
            int nextcell=dp[nr][nc];
            return max(1,nextcell-curr);
        };
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                int curr=dungeon[i][j];
                int rhealth=getmin(curr,i,j+1);
                int dhealth=getmin(curr,i+1,j);
                int next=min(rhealth,dhealth);
                int min_h;
                if(next!=INT_MAX){
                    min_h=next;
                }
                else{
                    min_h=curr>=0?1:1-curr;
                }
                dp[i][j]=min_h;
            }
        }
        return dp[0][0];
    }
};