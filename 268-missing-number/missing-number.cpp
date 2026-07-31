class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=0;
        for(auto i:nums){
            s=s+i;
        }
        int sum=0;
        for(int i=0;i<=nums.size();i++){
            sum=sum+i;
        }
        return sum-s;
    }
};