class DSU{
    vector<int>p;
    vector<int>s;
    public:
    DSU(int n){
        p.resize(n+1);
        s.resize(n+1);
        for(int i=0;i<=n;i++){
            p[i]=i;
            s[i]=1;
        }
    }
    int find(int node){
        if(p[node]!=node){
            return find(p[node]);
        }
        return node;
    }
    bool Union(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu!=pv){
            p[pu]=pv;
            s[pv]=s[pv]+s[pu];
            return true;
        }
        return false;
    }

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        DSU dsu(edges.size());
        for(auto i:edges){
            if(dsu.find(i[0])==dsu.find(i[1])){
                return i;
            }
            dsu.Union(i[0],i[1]);
        }
        return ans;
    }
};