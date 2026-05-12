class Solution {
public:
    long long check(int mid,vector<int>&nums){
        long long  a=0;
        for(auto i:nums){
            a=a+ceil(double(i)/double(mid));
        }
        return a;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int l=1;
        int r=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            r=max(r,nums[i]);
        }
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            cout<<mid<< " "<<check(mid,nums)<<endl;
            if(check(mid,nums)>h){
                l=mid+1;
            }
            else{
               r=mid-1;
            }
        }
        return l;
    }
};