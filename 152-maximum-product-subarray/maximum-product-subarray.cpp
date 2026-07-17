class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prev=1;
        int ans=-1e9;
        int post=1;
        for(int i=0;i<nums.size();i++){
            if(prev==0){
                prev=1;
            }
            if(post==0){
                post=1;
            }
            prev=prev*nums[i];
            post=post*nums[nums.size()-i-1];
            ans=max({ans,prev,post});
        }
        return ans;
    }
};