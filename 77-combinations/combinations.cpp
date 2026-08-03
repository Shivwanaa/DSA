class Solution {
public:
vector<vector<int>>ans;
    void check(int i,int n,int k,vector<int>t,vector<int>v){
        if(t.size()==k){
            ans.push_back(t);
            return ;
        }
        for(int j=i;j<=n;j++){
            t.push_back(j);
            check(j+1,n,k,t,v);
            t.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>t;
        vector<int>v(n+1,0);
        check(1,n,k,t,v);
        return ans;
    }
};