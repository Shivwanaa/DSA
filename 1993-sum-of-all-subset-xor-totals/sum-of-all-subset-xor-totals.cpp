class Solution {
public:
    int check(int i,vector<int>& nums,int xo){
        if(i==nums.size()){
            return xo;
        }
       return check(i+1,nums,xo^nums[i])+check(i+1,nums,xo);
    }
    int subsetXORSum(vector<int>& nums) {
        return check(0,nums,0);
    }
};