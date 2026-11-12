class Solution {
public:
vector<vector<int>>dp;
    int check(int i,vector<int>& stones,int diff,int s){
        if(i==stones.size()){
            return abs(diff);
        }
        if(dp[i][diff+s]!=-1){
            return dp[i][diff+s];
        }
        int sm=check(i+1,stones,diff+stones[i],s);
        int sp=check(i+1,stones,diff-stones[i],s);
        return dp[i][diff+s]=min(abs(sm),abs(sp));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int s=0;
        for(auto i:stones){
            s=s+i;
        }
        dp=vector<vector<int>>(stones.size(),vector<int>(s*2+1,-1));
        return check(0,stones,0,s);
    }
};