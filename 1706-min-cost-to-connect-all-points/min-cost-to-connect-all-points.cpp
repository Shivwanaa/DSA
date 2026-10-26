class DSU{
    public:
    vector<int>p;
    int n;
    DSU(int n){
        p.resize(n+1);
        for(int i=0;i<p.size();i++){
            p[i]=i;
        }
    }

    int find(int node){
        if(p[node]!=node){
            return p[node]=find(p[node]);
        }
        return p[node];
    }
    bool Union(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            return false;
        }
        p[pu]=pv;
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int,int,int>>arr;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                arr.push_back({d,i,j});
            }
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        DSU dsu(points.size());
        for(auto [d,i,j]:arr){
            if(dsu.find(i)==dsu.find(j)){
                continue;
            }
            dsu.Union(i,j);
            ans=ans+d;
        }
        return ans;

    }
};