class DSU{
    public:
    vector<int>p;
    int s=0;
    DSU(int n){
        p.resize(n);
        s=n;
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        s=n;
    }
    int find(int node){
        if(node!=p[node]){
            return p[node]=find(p[node]);
        }
        return p[node];
    }
    bool Union(int u,int v){
        int pu=p[u];
        int pv=p[v];
        if(pu==pv){
            return false;
        }
        p[pu]=pv;
        s--;
        return true;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU dsu(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(i!=j && isConnected[i][j]==1){
                    int a=dsu.find(i);
                    int b=dsu.find(j);
                    if(a!=b)
                    dsu.Union(i,j);
                }
            }
        }
        return dsu.s;
    }
};