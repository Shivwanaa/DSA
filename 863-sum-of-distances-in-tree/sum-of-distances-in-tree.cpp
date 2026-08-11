class Solution {
public:
    void check(unordered_map<int,vector<int>>&m,int n,int source,int p,vector<int>&ans,vector<int>&sub,int d){
        sub[source]=1;
        ans[0]+=d;
        for(auto i:m[source]){
            if(i!=p){
            check(m,n,i,source,ans,sub,d+1);
            sub[source]+=sub[i];
            }
        }
    }
    void check1(unordered_map<int,vector<int>>&m,int node,int p,vector<int>&sub,vector<int>&ans,int t,int n){
        ans[node]=t;
        for(auto i:m[node]){
            if(i!=p){
                check1(m,i,node,sub,ans,t+n-sub[i]-sub[i],n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>m;
        vector<int>ans1;
        vector<int>ans(n,0);
        for(auto i:edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        vector<int>sub(n,0);
        check(m,n,0,-1,ans,sub,0);
        check1(m,0,-1,sub,ans,ans[0],n);
        return ans;

    }
};