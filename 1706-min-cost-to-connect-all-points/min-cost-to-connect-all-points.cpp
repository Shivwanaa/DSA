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
        if(px==py){
            return false;
        }
        p[px]=py;
        s[py]=s[py]+s[px];
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int,int,int>>v;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                v.push_back({d,i,j});
            }
        }
        sort(v.begin(),v.end());
        int ans=0;
        DSU dsu(points.size());
        for(auto i:v){
            auto [a,b,c]=i;
            if(dsu.find(b)!=dsu.find(c)){
            dsu.Union(b,c);
            ans=ans+a;
            }
        }
        return ans;
    }
};