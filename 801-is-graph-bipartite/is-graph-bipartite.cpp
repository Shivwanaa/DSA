class DSU{
    public:
    vector<int>p;
    vector<int>s;
    DSU(int n){
        p.resize(n);
        s.resize(n,1);
        for(int i=0;i<n;i++){
            p[i]=i;
        }
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
        s[pv]=s[pv]+s[pu];
        return true;
    }
};
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        DSU dsu(graph.size());
        for(int node=0;node<graph.size();node++){
            for(auto i:graph[node]){
                if(dsu.find(i)==dsu.find(node)){
                    return false;
                }
                dsu.Union(graph[node][0],i);
            }
        }
        return true;
    }
};