class Solution {
public:

    int check(int i,vector<int>& nums, int target){
        if(target==0 && i==nums.size()){
            return 1;
        }
        if(i>=nums.size()){
            return 0;
        }
        int add=check(i+1,nums,target-nums[i]);
        int sub=check(i+1,nums,target+nums[i]);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return check(0,nums,target);
    }
};