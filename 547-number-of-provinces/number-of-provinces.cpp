class Solution {
public:
    void check(unordered_map<int,vector<int>>&m,int node,unordered_set<int>&v){
        if(v.count(node)){
            return;
        }
        v.insert(node);
        for(auto i:m[node]){
            check(m,i,v);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(i!=j && isConnected[i][j]==1){
                m[i].push_back(j);
                m[j].push_back(i);
                }
            }
        }
        unordered_set<int>v;
        int ans=0;
        for(int i=0;i<isConnected.size();i++){
            if(!v.count(i)){
            check(m,i,v);
            ans++;
            }
        }
        return ans;
    }
};