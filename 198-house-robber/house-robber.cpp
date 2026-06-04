class Solution {
public:
vector<int>m;
    int check(vector<int>& nums,int i){
        if(i>=nums.size()){
            return 0;
        }
        if(m[i]!=-1){
            return m[i];
        }
        int norob=check(nums,i+1);
        int rob=nums[i]+check(nums,i+2);
        m[i]= max(rob,norob);
        return m[i];
    }
    int rob(vector<int>& nums) {
        m=vector<int>(nums.size()+1,-1);
        return check(nums,0);
    }
};