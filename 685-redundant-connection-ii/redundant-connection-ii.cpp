class DSU{
    public:
    int n;
    vector<int>p;
    vector<int>s;
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
            return p[node]=find(p[node]);
        }
        return node;
    }
    bool Union(int u,int v){
        int pv=find(v);
        int pu=find(u);
        if(find(pu)==find(pv)){
            return false;
        }
        p[pu]=pv;
        s[pv]=s[pv]+s[pu];
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        //either dsu and cycle
        DSU dsu(edges.size());
        vector<int>cand1,cand2;
        vector<int>p(edges.size()+1,0);
        for(auto i:edges){
            if(p[i[1]]==0){
                p[i[1]]=i[0];
            }
            else{
                cand1={p[i[1]],i[1]};
                cand2={i[0],i[1]};
            }
        }
        for(auto i:edges){
            if(!cand2.empty() && i==cand2){
                continue;
            }
            else if(dsu.find(i[1])==dsu.find(i[0])){
                if(!cand1.empty()){
                    return cand1;
                }
                else{
                    return {i[0],i[1]};
                }
            }
            dsu.Union(i[1],i[0]);
        }
        return cand2;
    }
};