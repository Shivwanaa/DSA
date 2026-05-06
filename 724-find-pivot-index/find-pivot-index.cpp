class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s=0;
        for(auto i:nums){
            s=s+i;
        }
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(s-nums[i]-l==l){
                return i;
            }
            l=l+nums[i];
        }
        return -1;
    }
};