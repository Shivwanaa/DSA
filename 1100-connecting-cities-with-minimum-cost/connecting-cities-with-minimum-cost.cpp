class DSU{
    public:
    vector<int>p;
    vector<int>s;
    DSU(int n){
        p.resize(n+1);
        s.resize(n+1);
        for(int i=0;i<p.size();i++){
            p[i]=i;
            s[i]=1;
        }
    }
    int find(int node){
        if(node!=p[node]){
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
    int minimumCost(int n, vector<vector<int>>& connections) {
        int ans=0;
        DSU dsu(n);
        auto comp=[](vector<int>a,vector<int>b){
            return a[2]<b[2];
        };
        int sum=0;
        sort(connections.begin(),connections.end(),comp);
        for(auto i:connections){
            if(dsu.Union(i[0],i[1])){
                ans=ans+i[2];
                sum++;
            }
        }
        if(sum==n-1){
            return ans;
        }
        return -1;
    }
};