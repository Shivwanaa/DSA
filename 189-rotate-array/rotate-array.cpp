class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>t(nums.size());
        int j=0;
        k=k%nums.size();
        for(int i=nums.size()-k;i<nums.size();i++){
            t[j++]=nums[i];
        }
        for(int i=0;i<nums.size()-k;i++){
            t[j++]=nums[i];
        }
        for(int i=0;i<t.size();i++){
            nums[i]=t[i];
        }
    }
};