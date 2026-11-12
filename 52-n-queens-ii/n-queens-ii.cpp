class Solution {
public:
int ans=0;
    void check(int i,int n,unordered_set<int>r,unordered_set<int>c,unordered_set<int>pd,unordered_set<int>nd){
        if(i==n){
            ans++;
            return;
        }
        for(int j=0;j<n;j++){
            if(r.count(i)||c.count(j)||pd.count(i+j)||nd.count(i-j)){
                continue;
            }
            r.insert(i);
            c.insert(j);
            pd.insert(i+j);
            nd.insert(i-j);
            check(i+1,n,r,c,pd,nd);
            r.erase(i);
            c.erase(j);
            pd.erase(i+j);
            nd.erase(i-j);
        }
    }
    int totalNQueens(int n) {
        unordered_set<int>r,c,pd,nd;
        check(0,n,r,c,pd,nd);
        return ans;
    }
};