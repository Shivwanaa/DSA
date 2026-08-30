class DSU{
    public:
    vector<int>p;
    vector<int>s;
    DSU(int n){
        p.resize(n+1);
        s.resize(n+1);
        for(int i=0;i<n+1;i++){
            p[i]=i;
            s[i]=1;
        }
    }

    int find(int node){
        if(p[node]!=node){
           p[node] = find(p[node]); 
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
        s[pv]=s[pv]+s[pu];
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
        DSU dsu(points.size());
        int ans=0;
        for(auto [i,n1,n2]:v){
            if(dsu.find(n1)==dsu.find(n2)){
                continue;
            }
            dsu.Union(n1,n2);
            ans=ans+i;
        }
        return ans;
    }
};