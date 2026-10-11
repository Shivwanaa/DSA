class DSU{
    public:
    vector<int>p;
    DSU(int n){
        p.resize(n+1);
        for(int i=0;i<p.size();i++){
            p[i]=i;
        }
    }
    int find(int node){
        if(p[node]!=node){
            return p[node]=find(p[node]);
        }
        return node;
    }
    bool Union(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            return false;
        }
        p[pu]=pv;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        DSU dsu(edges.size());
        for(int i=0;i<edges.size();i++){
            if(dsu.find(edges[i][0])==dsu.find(edges[i][1])){
                return {edges[i][0],edges[i][1]};
            }
            dsu.Union(edges[i][0],edges[i][1]);
        }
        return ans;
    }
};