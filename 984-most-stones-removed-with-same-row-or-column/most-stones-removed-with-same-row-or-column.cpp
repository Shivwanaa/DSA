class DSU{
    public:
    vector<int>p;
    vector<int>s;
    int c=0;
    DSU(int n){
        p.resize(n);
        s.resize(n);
        for(int i=0;i<n;i++){
            s[i]=1;
            p[i]=i;
        }
        c=n;
    }
    int find(int node){
        if(p[node]!=node){
            return find(p[node]);
        }
        return p[node];
    }
    bool Union(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py){
            return false;
        }
        p[px]=py;
        s[py]=s[px]+s[py];
        c--;
        return true;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu(stones.size());
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    dsu.Union(i,j);
                }
            }
        }
        return stones.size()-dsu.c;
    }
};