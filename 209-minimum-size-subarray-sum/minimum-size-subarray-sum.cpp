class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int ans=1e9;
        int s=0;
        for(int j=0;j<nums.size();j++){
            s=s+nums[j];
            while(s>=target){
                s=s-nums[i];
                ans=min(ans,j-i+1);
                i++;
            }
        }
        if(ans==1e9){
            return 0;
        }
        return ans;
    }
};