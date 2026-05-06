class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //O(n2)
        //prefix multiply
        int fnum=1,bnum=1;
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=fnum;
            fnum=fnum*nums[i];
        }
        for(int i=0;i<nums.size();i++){
            ans[nums.size()-i-1]=ans[nums.size()-i-1]*bnum;
            bnum=bnum*nums[nums.size()-i-1];
        }
        return ans;
    }
};