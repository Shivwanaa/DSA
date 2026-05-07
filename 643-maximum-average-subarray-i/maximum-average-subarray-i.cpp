class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=-1e9;
        int i=0;
        double s=0;
        for(int j=0;j<nums.size();j++){
            s=s+nums[j];
            if(j-i+1==k){
                ans=max(ans,s/k);
                s=s-nums[i];
                i++;
            }
        }
        return ans;
    }
};