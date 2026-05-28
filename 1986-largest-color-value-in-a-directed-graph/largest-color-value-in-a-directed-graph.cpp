class Solution {
public:
int mc=0;
    int check(int node,unordered_map<int,vector<int>>&m,unordered_set<int>&v,unordered_set<int>&visting, vector<vector<int>> &dp,string &colors){
        if(visting.count(node)){
            return 1e9;
        }
        if(v.count(node)){
            return dp[node][colors[node]-'a'];
        }
        v.insert(node);
        visting.insert(node);
        for(auto i:m[node]){
                if(check(i,m,v,visting,dp,colors)==1e9){
                    return 1e9;
                }
                for(int j=0;j<26;j++){
                    dp[node][j]=max(dp[node][j], dp[i][j]);
                }
        }
        dp[node][colors[node]-'a']++;
        visting.erase(node);
        return dp[node][colors[node] - 'a'];
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        //traverse all nodes, in any path the most frequent colr is number is the ans
        //if cycle is there return -1;
        unordered_map<int,vector<int>>m;
        for(auto i:edges){
            m[i[0]].push_back(i[1]);
        }
        unordered_set<int>v;
        int ans=0;
        int n=colors.size();
        vector<vector<int>> dp(n, vector<int>(26, 0));
        for(int i=0;i<colors.size();i++){
            
            unordered_set<int>visting;
            ans=max(ans,check(i,m,v,visting,dp,colors));
            
        }
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};