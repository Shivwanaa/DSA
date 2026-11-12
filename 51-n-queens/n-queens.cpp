class Solution {
public:
vector<vector<string>>ans;
    void check(int i,vector<string>tp,unordered_set<int>r,unordered_set<int>c,unordered_set<int>pd,unordered_set<int>nd){
        if(i==tp.size()){
            ans.push_back(tp);
            return;
        }
        for(int j=0;j<tp.size();j++){
            if(r.count(i)||c.count(j)||pd.count(i+j)||nd.count(i-j)){
                continue;
            }
            tp[i][j]='Q';
            r.insert(i);
            c.insert(j);
            pd.insert(i+j);
            nd.insert(i-j);
            check(i+1,tp,r,c,pd,nd);
            tp[i][j]='.';
            r.erase(i);
            c.erase(j);
            pd.erase(i+j);
            nd.erase(i-j);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>tp(n,string(n,'.'));
        unordered_set<int>r,c,pd,nd;
        check(0,tp,r,c,pd,nd);
        return ans;
    }
};