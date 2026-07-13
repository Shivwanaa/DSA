class Solution {
public:
set<vector<int>>anst;
    void check(int i,vector<int>& candidates, int target,vector<int>t){
        if(target==0 && i==candidates.size()){
            sort(t.begin(),t.end());
            anst.insert(t);
            return;
        }
        if(i==candidates.size() || target<0){
            return;
        }
        t.push_back(candidates[i]);
        check(i,candidates,target-candidates[i],t);
        t.pop_back();
        check(i+1,candidates,target,t);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        check(0,candidates,target,{});
        for(auto i:anst){
            ans.push_back(i);
        }
        return ans;

    }
};