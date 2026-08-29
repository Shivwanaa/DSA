class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int temp=1e9;
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int m=nums[l]+nums[r]+nums[i];
                if(abs(target-m)<temp){
                    temp=abs(target-m);
                    ans=m;
                }
                if(m<target){
                    l++;
                }
                else{
                    r--;
                }

            }
        }
        return ans;
    }
};