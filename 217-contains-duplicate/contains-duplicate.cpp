class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //sort it, if curr==prev O(nlogn)
        //use map O(n)-space, if map size!=nums size 
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                return true;
            }
            m[nums[i]]++;
        }
        return false;
    }
};