class DSU{
    public:
    vector<int>p;
    int n;
    DSU(int n){
        p.resize(n+1);
        for(int i=0;i<=n;i++){
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
        return true;
    }
};
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        DSU dsu(n);
        unordered_map<int,vector<int>>m;
        for(auto i:dislikes){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        for(auto i:m){
            if(i.second.size()){
                int fd=i.second[0];
                for(auto j:i.second){
                    if(dsu.find(j)==dsu.find(i.first)){
                        return false;
                    }
                    dsu.Union(fd,j);
                }
            }
        }
        return true;
    }
};