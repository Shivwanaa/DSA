class DSU{
    public:
    vector<int>p;
    vector<int>s;
    DSU(int n){
        p.resize(n+1);
        s.resize(n+1);
        for(int i=0;i<n+1;i++){
            p[i]=i;
            s[i]=1;
        }
    }

    int find(int node){
        if(p[node]!=node){
           p[node] = find(p[node]); 
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
        s[pv]=s[pv]+s[pu];
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for(auto i:edges){
            if(dsu.find(i[0])==dsu.find(i[1])){
                return {i[0],i[1]};
            }
            dsu.Union(i[0],i[1]);
        }
        return {};
    }
};