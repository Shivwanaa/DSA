class Solution {
public:
    bool check(int node,int p,unordered_map<int,vector<int>>&m,unordered_set<int>&v){
        if(v.count(node)){
            return true;
        }
        v.insert(node);
        for(auto i:m[node]){
            if(p!=i){
            if(check(i,node,m,v)){
                return true;
            }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //if there is a cycle its not a valid tree
        //can be more than 1 compoonent as well
        unordered_map<int,vector<int>>m;
        unordered_set<int>v;
        for(auto i:edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        if(!check(0,-1,m,v) && v.size()==n){
            return true;
        }
        return false;
    }
};