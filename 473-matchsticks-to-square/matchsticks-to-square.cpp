class Solution {
public:
    bool check(vector<int>& nums,int i,int a,int b,int c,int d){
        if(i==nums.size() && !a && !b && !c &&!d){
            return true;
        }
        if(a>=nums[i]){
            if(check(nums,i+1,a-nums[i],b,c,d)){
                return true;
            }
        }
        if(b>=nums[i]){
            if(check(nums,i+1,a,b-nums[i],c,d))
            return true;
        }
        if(c>=nums[i]){
            if(check(nums,i+1,a,b,c-nums[i],d))
            return true;
        }
        if(d>=nums[i]){
            if(check(nums,i+1,a,b,c,d-nums[i]))
            return true;
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();i++){
            s=s+nums[i];
        }
        if(s%4!=0){
            return false;
        }
        s=s/4;
        sort(nums.rbegin(),nums.rend());
        return check(nums,0,s,s,s,s);
    }
};