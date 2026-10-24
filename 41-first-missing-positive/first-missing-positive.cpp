class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>v(nums.begin(),nums.end());
        for(int i=1;i<=nums.size();i++){
            if(!v.count(i)){
                return i;
            }
        }
        return nums.size()+1;
    }
};