class Solution {
public:
    void check(int node,unordered_map<int,vector<int>>m,unordered_set<int>&v){
        if(v.count(node)){
            return;
        }
        v.insert(node);
        for(auto i:m[node]){
            if(!v.count(i))
            check(i,m,v);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(i!=j && isConnected[i][j]==1)
                m[i].push_back(j);
            }
        }
        unordered_set<int>v;
        for(int i=0;i<isConnected.size();i++){
            if(!v.count(i)){
            check(i,m,v);
            ans++;
            }
        }
        return ans;
    }
};