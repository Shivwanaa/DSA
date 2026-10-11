class DSU{
    public:
    vector<int>p;
    int c;
    DSU(int n){
        p.resize(n+1);
        c=0;
        for(int i=0;i<p.size();i++){
            p[i]=i;
        }
    }
    int find(int node){
        if(p[node]!=node){
            return p[node]=find(p[node]);
        }
        return node;
    }
    bool Union(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            return false;
        }
        c--;
        p[pu]=pv;
        return true;
    }
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int>ans;
        DSU dsu(m*n);
        auto index=[](int i,int j,int m,int n){
          return i*n+j;  
        };
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        vector<bool>land(m*n,false);
        for(auto i:positions){
            int r=i[0];
            int c=i[1];
            
            int idx1=index(r,c,m,n);
            if (land[idx1]) {
                ans.push_back(dsu.c);
                continue;
            }
            land[idx1]=true;
            dsu.c++;
            for(auto k:dir){
                if(r+k[0]<0||r+k[0]>=m||c+k[1]<0||c+k[1]>=n){
                    continue;
                }
                int idx2=index(r+k[0],c+k[1],m,n);
                if (land[idx2]) {
                    dsu.Union(idx1,idx2);
                }
                
            }
            ans.push_back(dsu.c);
        }
        return ans;
    }
};