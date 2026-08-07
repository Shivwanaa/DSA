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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu(accounts.size());
        unordered_map<string,int>v;
        unordered_map<int,vector<string>>m;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(v.count(accounts[i][j])){
                    dsu.Union(v[accounts[i][j]],i);
                }
                else{
                v[accounts[i][j]]=i;
                }
            }
        }
        for(auto i:v){
            m[dsu.find(i.second)].push_back(i.first);
        }
        vector<vector<string>>ans;
        for(auto i:m){
            
            sort(i.second.begin(),i.second.end());
            vector<string>t;
            t=i.second;
            t.insert(t.begin(),accounts[i.first][0]);
            ans.push_back(t);

        }
        return ans;
    }
};