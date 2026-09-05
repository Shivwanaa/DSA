class DSU{
    public:
    vector<int>p;
    int s=0;
    DSU(int n){
        p.resize(n+1);
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        s=n;
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
        s--;
        p[pu]=pv;
        return true;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto i:edges){
            dsu.Union(i[0],i[1]);
        }
        return dsu.s;
    }
};