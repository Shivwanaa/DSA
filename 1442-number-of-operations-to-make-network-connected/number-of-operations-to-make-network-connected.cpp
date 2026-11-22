class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&m,int node,vector<int>&v){
        v[node]=1;
        for(auto i:m[node]){
            if(v[i]==0){
                v[i]=1;
            dfs(m,i,v);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>v(n,0);
        int ans=0;
        if(n-1>connections.size()){
            return -1;
        }
        unordered_map<int,vector<int>>m;
        for(auto i:connections){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(v[i]==0){
            dfs(m,i,v);
            ans++;
            }
        }
        return ans-1;
    }
};