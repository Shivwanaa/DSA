class DSU{
    public:
    vector<int>p;
    int c=0;
    vector<int>s;
    DSU(int n){
        p.resize(n);
        s.resize(n);
        for(int i=0;i<n;i++){
            p[i]=i;
            s[i]=1;
        }
        c=n;
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
        s[pv]=s[pu]+s[pv];
        c--;
        return true;
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int ans=0;
        for(auto i:edges){
            dsu.Union(i[0],i[1]);
        }
        unordered_map<int,int>m;
        for(auto i:edges){
            m[dsu.find(i[0])]++;
        }
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i){
                int no=dsu.s[i];
                int e=no*(no-1)/2;
                if(e==m[i]){
                    ans++;
                }
            }
        }
        return ans;
    }
};