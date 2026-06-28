class DSU{
    public:
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
            return find(p[node]);
        }
        return p[node];
    }
    bool Union(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px!=py){
            p[px]=py;
            s[py]=s[px]+s[py];
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        //build a well or a pipe
        int ans=0;
        int a=n+1;
        for(int i=0;i<n;i++){
            pipes.push_back({0,i+1,wells[i]});
        }
        auto comp=[](vector<int>a,vector<int>b){
            return a[2]<b[2];
        };
        sort(pipes.begin(),pipes.end(),comp);
        // map<pair<int,int>,int>m;
        // for(auto i:pipes){
        //     if(m.find({i[0],i[1]})!=m.end() || m.find({i[1],i[0]})!=m.end()){
        //         continue;
        //     }
        //     m[{i[0],i[1]}]=i[2];
        // }
        DSU dsu(n+1);
        for(auto i:pipes){
            if(dsu.Union(i[0],i[1])){
                ans=ans+i[2];
            }
        }
        return ans;
    }
};