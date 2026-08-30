class DSU{
    public:
    vector<int>p;
    int n;
    int tot;
    DSU(int n){
        p.resize(n+1);
        for(int i=0;i<=n;i++){
            p[i]=i;
        }
        tot=n;
    }
    int find(int node){
        if(p[node]!=node){
            return find(p[node]);
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
        tot--;
        return true;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        DSU dsu(n);
        for(auto i:connections){
            if(dsu.find(i[0])!=dsu.find(i[1]))
            dsu.Union(i[0],i[1]);
        }
        return dsu.tot-1;
    }
};