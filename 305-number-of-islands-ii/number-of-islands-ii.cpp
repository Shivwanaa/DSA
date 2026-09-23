class DSU{
    
public:
vector<int>P;
    vector<int>S;
    int count;
    DSU(int n){
        P.resize(n+1);
        S.resize(n+1);
        count=0;
        for(int i=0;i<=n;i++){
            P[i]=i;
            S[i]=1;
        }
    }
    int find(int node){
        if(P[node]!=node){
            P[node]=find(P[node]);
        }
        return P[node];
    }
    bool Union(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            return false;
        }
        count--;
        P[pv]=pu;
        S[pu]=S[pu]+S[pv];
        return true;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        auto index=[&](int r,int c){
            return r*n+c;
        };
        vector<int>ans;
        unordered_set<int>l;
        DSU dsu(m*n);
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<positions.size();i++){
            
            int pos=index(positions[i][0],positions[i][1]);
            if(l.count(pos)){
                ans.push_back(dsu.count);
                continue;
            }
            dsu.count++;
            l.insert(pos);
            for(auto j:dir){
                int nr=j[0]+positions[i][0];
                int nc=j[1]+positions[i][1];
                int npos=index(nr,nc);
                if(nr>=0&& nr<m && nc>=0 && nc<n && l.count(npos)){
                    dsu.Union(pos,npos);
                }
            }
            ans.push_back(dsu.count);
        }
        return ans;
    }
};