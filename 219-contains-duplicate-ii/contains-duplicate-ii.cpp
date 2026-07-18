class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>v;
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(v.count(nums[j])){
                return true;
            }
            v.insert(nums[j]);
            if(j-i+1>k){
                v.erase(nums[i]);
                i++;
            }
        }
        return false;
    }
};