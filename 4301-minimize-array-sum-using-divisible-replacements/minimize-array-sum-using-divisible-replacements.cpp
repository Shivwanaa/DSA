class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long ans=0;
        unordered_set<int>pres;
        for(int i=0;i<nums.size();i++){
            pres.insert(nums[i]);
        }
        for(auto x:nums){
            int best=x;
            for(int d=1;d*d<=(x);d++){
                if(x%d==0){
                    if(pres.count(d)){
                        best=min(best,d);
                    }
                    int o=x/d;
                    if(pres.count(o)){
                        best=min(best,o);
                    }
                }
            }
            ans=ans+best;
        }
        return ans;
    }
};