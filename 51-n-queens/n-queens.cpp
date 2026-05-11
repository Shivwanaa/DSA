class Solution {
public:
vector<vector<string>>ans;
//place q in 1 position
//relative to that place the next q in a placee where its not attacking and then the next queen,-recursive manner
    void check(int i,int n,vector<string>t,unordered_set<int>c,unordered_set<int>nd,unordered_set<int>pd){
        if(i==n){
            ans.push_back(t);
            return;
        }
        for(int j=0;j<n;j++){
            if(!c.count(j) && !nd.count(i-j) && !pd.count(i+j)){
                c.insert(j);
                nd.insert(i-j);
                pd.insert(i+j);
                t[i][j]='Q';
                check(i+1,n,t,c,nd,pd);
                t[i][j]='.';
                c.erase(j);
                nd.erase(i-j);
                pd.erase(i+j);
            }
            else{
                continue;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>t(n,string(n,'.'));
        unordered_set<int>c,nd,pd;
        check(0,n,t,c,nd,pd);
        return ans;
    }
};