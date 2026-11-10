class Solution {
public:
vector<int>dp;
    bool check(int start,vector<int>& arr,vector<bool>vis){
        if(start<0||start>=arr.size()){
            return false;
        }
        if(vis[start]){
            return false;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        if(arr[start]==0){
            return true;
        }
        vis[start]=1;
        return dp[start]=check(start+arr[start],arr,vis)||check(start-arr[start],arr,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        dp=vector<int>(arr.size()+1,-1);
        vector<bool>vis(arr.size(),0);
        return check(start,arr,vis);

    }
};