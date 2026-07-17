class DSU{
    public:
    vector<int>p;
    vector<int>s;
    DSU(int n){
        p.resize(n);
        s.resize(n);
        for(int i=0;i<n;i++){
            p[i]=i;
            s[i]=1;
        }
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
        if(px==py) return false;
        p[px]=py;
        s[px]=s[py]+s[px];
        return true;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for(auto i:equations){
            if(i[1]=='=')
            dsu.Union(i[0]-'a',i[3]-'a');
        }
        for(auto i:equations){
            if(i[1]=='!' && dsu.find(i[0]-'a')==dsu.find(i[3]-'a')){
                return false;
            }
        }
        return true;
    }
};