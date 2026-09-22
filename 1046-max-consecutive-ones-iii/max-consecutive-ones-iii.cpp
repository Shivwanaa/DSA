class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int c=0;
        int l=0;
        int ans=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                c++;
            }
            while(c>k){
                if(nums[i]==0){
                    c--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};