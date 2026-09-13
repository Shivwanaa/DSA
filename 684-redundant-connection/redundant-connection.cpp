class DSU{
    public:
    vector<int>p;
    DSU(int n){
        p.resize(n+1);
        for(int i=1;i<=n;i++){
            p[i]=i;
        }
    }
    int find(int node){
        if(p[node]!=node){
            return p[node]=find(p[node]);
        }
        return p[node];
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
        for(auto i:edges){
            int a=dsu.find(i[0]);
            int b=dsu.find(i[1]);
            if(a==b){
                return {i[0],i[1]};
            }
            dsu.Union(i[0],i[1]);
        }
        return ans;
    }
};