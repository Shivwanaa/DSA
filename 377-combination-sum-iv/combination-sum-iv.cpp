class Solution {
public:
vector<int>m;
    int check(vector<int>& nums, int target){
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(m[target]!=-1){
            return m[target];
        }
        int ans=0;
        //when there is a for loop dont do take and nottake, it will automatically do it
        for(int i=0;i<nums.size();i++){
            ans=ans+check(nums,target-nums[i]);
        }
        m[target]=ans;
        return m[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        m=vector<int>(target+1,-1);
        return check(nums,target);
    }
};