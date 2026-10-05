class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int ans=0,flips=k;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                flips--;
                while(flips<0){
                    if(nums[i]==0){
                        flips++;
                    }
                    i++;
                }
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};