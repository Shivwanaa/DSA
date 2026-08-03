class Solution {
public:
    bool check(int j,int curr,int s,vector<int>& nums, int k,vector<int>&v){
        if(k==1){
            return true;
        }
        if(s==curr){
            return check(0,0,s,nums,k-1,v);
        }
        for(int i=j;i<nums.size();i++){
            if(v[i]){
                continue;
           }
           if(nums[i]+curr>s){
            continue;
           }
           v[i]=1;
           if(check(i+1,nums[i]+curr,s,nums,k,v)){
            return true;
           }
           v[i]=0;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s=0;
        for(int i=0;i<nums.size();i++){
            s=s+nums[i];
        }
        if(s%k!=0){
            return false;
        }
        vector<int>v(nums.size(),0);
        sort(nums.rbegin(),nums.rend());
        return check(0,0,s/k,nums,k,v);
    }
};