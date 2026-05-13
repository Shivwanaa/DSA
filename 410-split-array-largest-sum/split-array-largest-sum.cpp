class Solution {
public:
    int check(int mid,vector<int>& nums){
        int a=1;
        int s=0;
        for(int i=0;i<nums.size();i++){
            s=s+nums[i];
            if(s>mid){
                s=nums[i];
                a++;
            }
        }
        return a;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        for(int i=0;i<nums.size();i++){
            l=max(l,nums[i]);
            r+=nums[i];
        }
        //32,2
        while(l<=r){
            int mid=(l+r)/2;
            cout<<check(mid,nums)<<endl;
            if(check(mid,nums)<=k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};