class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int i=0;
        int a=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                a++;
            }
            while(a>k){
                // ans=max(ans,j-i);
                if(nums[i]==0){
                    a--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};