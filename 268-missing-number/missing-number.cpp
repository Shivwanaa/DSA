class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xo=nums.size();
        for(int i=0;i<nums.size();i++){
            xo=xo^i^nums[i];
        }
        return xo;
    }
};