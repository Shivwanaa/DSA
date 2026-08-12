class Solution {
public:
vector<vector<int>>dp;
    int check(int i,int j, vector<int>& cuts){
        if(j-i<=1){
            return 0;
        }
        int ans=1e9;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=i+1;k<j;k++){
            ans=min(ans,cuts[j]-cuts[i]+check(i,k,cuts)+check(k,j,cuts));
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        dp=vector<vector<int>>(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return check(0,cuts.size()-1,cuts);
    }
};