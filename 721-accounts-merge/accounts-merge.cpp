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
        if(px==py) return false;
        p[px]=py;
        s[px]=s[py]+s[px];
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
                else{
                m[accounts[i][j]]=i;
                }
            }
        }
        map<int,vector<string>>temp;
        for(auto i:m){
            temp[dsu.find(i.second)].push_back(i.first);
        }
        for(auto i:temp){
            // vector<string>t;
            sort(i.second.begin(),i.second.end());
            i.second.insert(i.second.begin(),accounts[i.first][0]);
            ans.push_back(i.second);
        }
        return ans;
    }
};