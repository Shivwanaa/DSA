class DSU{
    vector<int>p;
    vector<int>s;
    
public:
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DSU dsu(n);
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] ||stones[i][1]==stones[j][1]){
                    dsu.Union(i,j);
                }
            }
        }
        return stones.size()-dsu.c;
    }
};