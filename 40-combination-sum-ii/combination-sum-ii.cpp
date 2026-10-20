class Solution {
public:
vector<vector<int>>ans;
    void check(int i,vector<int>& nums, int target,vector<int>tp){
        if(target==0 && i==nums.size()){
            ans.push_back(tp);
            return;
        }
        if(target<0||i>=nums.size()){
            return ;
        }
        tp.push_back(nums[i]);
        check(i+1,nums,target-nums[i],tp);
        // int j=i;
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        tp.pop_back();
        check(i+1,nums,target,tp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>tp;
        check(0,candidates,target,tp);
        return ans;
    }
};