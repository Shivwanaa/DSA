class DSU{
public:
vector<int>p;
    vector<int>s;
    vector<int>e;
    int c;
    DSU(int n){
        c=n;
        e.resize(n);
        p.resize(n);
        s.resize(n);
        for(int i=0;i<n;i++){
            p[i]=i;
            s[i]=1;
        }
    }
    int find(int x){
        if(p[x]!=x){
            return find(p[x]);
        }
        return p[x];
    }
    bool Union(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py){
            return false;
        }
        c--;
        p[px]=py;
        s[py]=s[py]+s[px];
        return true;
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,int>m;
        DSU dsu(n);
        for(auto i:edges){
            dsu.Union(i[0],i[1]);
        }
        for(auto i:edges){
            int ro=dsu.find(i[0]);
            m[ro]++;
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i){
                int nodes=dsu.s[i];
                int ee=(nodes*(nodes-1))/2;
                if(m[i]==ee){
                    c++;
                }
            }
        }
        return c;
    }
};