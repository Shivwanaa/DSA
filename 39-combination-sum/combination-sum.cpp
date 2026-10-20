class Solution {
public:
vector<vector<int>>ans;
    void check(int i,vector<int>& nums, int target,vector<int>&tp){
        if(target==0){
            ans.push_back(tp);
            return;
        }
        if(target<0||i>=nums.size()){
            return;
        }
        tp.push_back(nums[i]);
        check(i,nums,target-nums[i],tp);
        tp.pop_back();
        check(i+1,nums,target,tp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>tp;
        check(0,candidates,target,tp);
        return ans;
    }
};