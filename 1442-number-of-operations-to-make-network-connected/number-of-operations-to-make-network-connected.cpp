class DSU{
    public:
    vector<int>p;
    vector<int>s;
    int c;

    DSU(int n){
        c=n;
        p.resize(n);
        s.resize(n);
        for(int i=0;i<n;i++){
            p[i]=i;
            s[i]=1;
        }
    }
    int find(int x){
        if(x!=p[x]){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        //count no of unions and also no of excess wires inside each union
        if(connections.size()<n-1){
            return -1;
        }
        DSU dsu(n);
        for(auto i:connections){
            if(dsu.find(i[0])!=dsu.find(i[1]))
            dsu.Union(i[0],i[1]);
        }
        return dsu.c-1;
    }
};