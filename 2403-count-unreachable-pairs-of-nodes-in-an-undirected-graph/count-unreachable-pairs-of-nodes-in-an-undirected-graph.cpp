class DSU{
public:
vector<int>p;
    vector<int>s;
int c=0;
    DSU(int n){
        p.resize(n);
        s.resize(n);
        for(int i=0;i<n;i++){
            p[i]=i;
            s[i]=1;
        }
    }
    int find(int x){
        if(p[x]!=x){
            p[x] = find(p[x]);
        }
        return p[x];
    }
    bool Union(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py){
            return false;
        }
        p[px]=py;
        s[py]=s[px]+s[py];
        return true;
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=0;
        DSU dsu(n);
        for(auto i:edges){
            dsu.Union(i[0],i[1]);
        }
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[dsu.find(i)]++;
        }
        long long r=n;
        for(auto i:m){
            int c=i.second;
            ans+=c*(r-c);
            r-=c;
        }
        return ans;
    }
};