class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>v;
        for(auto i:nums){
            if(v.count(i)){
                return true;
            }
            v.insert(i);
        }
        return false;
    }
};