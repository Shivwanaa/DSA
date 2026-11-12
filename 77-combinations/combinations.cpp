class Solution {
public:
vector<vector<int>>ans;
    void check(int i,int n,int k,vector<int>tp){
        if(tp.size()==k){
            ans.push_back(tp);
            return;
        }
        for(int j=i+1;j<=n;j++){
            tp.push_back(j);
            check(j,n,k,tp);
            tp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>tp;
        unordered_set<int>v;
        check(0,n,k,tp);
        return ans;
    }
};