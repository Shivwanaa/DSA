class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //subarray-no sorting shld be done
        //kadanes algorithm-currsum<0 :reset currsum=0
        int cs=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            cs=cs+nums[i];
            ans=max(ans,cs);
            if(cs<0){
                cs=0;
            }
        }
        return ans;
    }
};