class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>l(nums.size());
        vector<int>r(nums.size());
        l[0]=1;
        int p=1;
        for(int i=1;i<nums.size();i++){
            p=p*nums[i-1];
            l[i]=p;
        }
        r[nums.size()-1]=1;
        p=1;
        for(int i=nums.size()-2;i>=0;i--){
            p=p*nums[i+1];
            r[i]=p;
        }
        for(int i=0;i<nums.size();i++){
            l[i]=l[i]*r[i];
        }
        return l;
    }
};