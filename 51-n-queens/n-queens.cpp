class Solution {
public:
vector<vector<string>>ans;
    void check(int i,vector<string>t,int n,unordered_set<int>c,unordered_set<int>pd,unordered_set<int>nd){
        if(i==n){
            ans.push_back(t);
            return;
        }
        for(int k=0;k<n;k++){
            if(c.count(k) || pd.count(i+k)|| nd.count(i-k)){
                continue;
            }
            pd.insert(i+k);
            nd.insert(i-k);
            c.insert(k);
            t[i][k]='Q';
            check(i+1,t,n,c,pd,nd);
            t[i][k]='.';
            pd.erase(i+k);
            nd.erase(i-k);
            c.erase(k);
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int>c;
        unordered_set<int>pd;
        unordered_set<int>nd;
        vector<string>t(n,string(n,'.'));
        check(0,t,n,c,pd,nd);
        return ans;
    }
};