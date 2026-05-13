class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // unordered_map<int,int>m;
        int i=0;
        int o=0;
        int a=0;
        int ans=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2==1){
                o++;
            }
            if(o==k){
                a=0;
                while(o==k){
                    a++;
                    if(nums[i]%2!=0){
                        o--;
                    }
                    i++;
                }
            }
            ans=ans+a;
        }
        return ans;
    }
};