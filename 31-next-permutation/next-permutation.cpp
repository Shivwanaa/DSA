class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j=nums.size()-1;
        while(j>0){
            if(nums[j-1]>=nums[j]){
                j--;
            }
            else{
                break;
            }
        }
        if(j==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int i=nums.size()-1;
        int idx=0;
        while(i>=j){
            if(nums[i]>nums[j-1]){
                idx=i;
                break;
            }
            i--;
        }
        swap(nums[j-1],nums[idx]);
        reverse(nums.begin()+j,nums.end());
        return;
    }
};