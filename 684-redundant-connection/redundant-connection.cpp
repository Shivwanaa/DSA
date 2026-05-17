class Solution {
public:
    bool check(unordered_map<int,vector<int>>&m,int node,int p,unordered_set<int>&v){
        if(v.count(node)){
            return true;
        }
        v.insert(node);
        for(auto i:m[node]){
               if(i!=p && check(m,i,node,v)){
                return true;
               }
            
        }
        return false;;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        unordered_map<int,vector<int>>m;
        for(auto i:edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
            unordered_set<int>v;
            if(check(m,i[0],-1,v)){
                return {i[0],i[1]};
            }
        }
        return ans;
    }
};