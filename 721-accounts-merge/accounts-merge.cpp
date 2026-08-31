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
        p[pv]=pu;
        s[pu]=s[pv]+s[pu];
        return true;
    }
};
class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>>ans;
        unordered_map<string,int>m;
        DSU dsu(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])!=m.end()){
                    dsu.Union(m[accounts[i][j]],i);
                }
                else
                m[accounts[i][j]]=i;
            }
        }
        unordered_map<int,vector<string>>mp;
        for(auto i:m){
            mp[dsu.find(i.second)].push_back(i.first);
        }
        for(auto i:mp){
            vector<string>t;
            for(auto j:i.second){
                t.push_back(j);
            }
            sort(t.begin(),t.end());
            t.insert(t.begin(),accounts[i.first][0]);
            ans.push_back(t);
        }

        return ans;
    }
};