class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int mid;
        int ans=0;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[l]<=nums[r]){
                ans=nums[l];
                return ans;
            }
            else if(nums[l]<=nums[mid]){
                ans=nums[l];
                l=mid+1;
            }
            else{
                r=mid;
                ans=nums[mid];
            }
        }
        return ans;
    }
};