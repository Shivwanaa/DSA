class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[i]+nums[j]<=limit){
                ans++;
                i++;
                j--;
                
            }
            else{
                j--;
                ans++;
            }
        }
        return ans;
    }
};