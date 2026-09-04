class Solution {
public:
int ans=0;
    void check(unordered_map<int,vector<pair<int,int>>>&m,int node,unordered_set<int>&v){
        v.insert(node);
        for(auto i:m[node]){
            if(!v.count(i.first)){
            ans=ans+i.second;
            check(m,i.first,v);
        }
    }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto i:connections){
            m[i[0]].push_back({i[1],1});
            m[i[1]].push_back({i[0],0});
        }
        unordered_set<int>v;
        check(m,0,v);
        return ans;
    }
};