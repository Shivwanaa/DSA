class Solution {
public:
    int check(vector<int>& coins, int amount,int i,vector<vector<int>>&m){
        if(amount==0){
            return 0;
        }
        if(i==coins.size() || amount<0){
            return 1e9;
        }
        if(m[i][amount]!=-1){
            return m[i][amount];
        }
        int p=1+check(coins,amount-coins[i],i,m);
        int np=check(coins,amount,i+1,m);
        m[i][amount]=min(p,np);
        return m[i][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>>m(coins.size()+1,vector<int>(amount+1,-1));
        int ans=check(coins,amount,0,m);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};