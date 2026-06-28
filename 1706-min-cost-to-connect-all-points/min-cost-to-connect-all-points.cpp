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
            s[py]=s[py]+s[px];
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //the emax distance shld be minimized
        vector<tuple<int,int,int>>dist;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                dist.push_back({d,i,j});
            }
        }
        sort(dist.begin(),dist.end());
        int ans=0;
        DSU dsu(points.size());
        for(const auto[a,b,c]:dist){
            if(dsu.Union(b,c)){
                ans=ans+a;
            }
        }
        return ans;
    }
};