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
    int find(int x){
        if(p[x]!=x){
            return find(p[x]);
        }
        return p[x];
    }
    bool Union(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py){
            return false;
        }
        p[px]=py;
        s[py]=s[px]+s[py];
        return true;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mail;
        int l=0;
        DSU dsu(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mail.find(accounts[i][j])!=mail.end()){
                    dsu.Union(mail[accounts[i][j]],i);
                }
                else{
                mail[accounts[i][j]]=i;
                }
            }
        }
        vector<vector<string>>ans;
        map<int,vector<string>>anst;
        for(auto i:mail){
            anst[dsu.find(i.second)].push_back(i.first);
        }
        for(auto i:anst){
            vector<string>t;
            sort(i.second.begin(),i.second.end());
            t.push_back(accounts[i.first][0]);
            t.insert(t.end(),i.second.begin(),i.second.end());
            ans.push_back(t);
        }
        return ans;
    }
};