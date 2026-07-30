class Solution {
public:
vector<vector<int>>ans;
    void check(int i,vector<int>t,vector<int>& candidates, int target){
        if(i==candidates.size() && target==0){
            ans.push_back(t);
            return;
        }
        if(target<0||i>=candidates.size()){
            return;
        }
        t.push_back(candidates[i]);
        check(i+1,t,candidates,target-candidates[i]);
        int j=i;
        while(j+1<candidates.size() && candidates[i]==candidates[j+1]){
            j++;
        }
        t.pop_back();
        check(j+1,t,candidates,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>t;
        sort(candidates.begin(),candidates.end());
        check(0,t,candidates,target);
        return ans;
    }
};