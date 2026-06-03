class Solution {
public:
vector<vector<int>>m;
    int check(vector<int>& nums, int target,int i,int s){
        if(s==target && i==nums.size()){
            return 1;
        }
        if(i>=nums.size()){
            return 0;
        }
        int p1=check(nums,target,i+1,s+nums[i]);
        int p2=check(nums,target,i+1,s-nums[i]);
        return p1+p2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        return check(nums,target,0,0);
    }
};