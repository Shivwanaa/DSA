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
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>m;
        for(auto i:edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        unordered_set<int>v;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!v.count(i)){
            check(m,i,v);
            ans++;
            }
        }
        return ans;
    }
};