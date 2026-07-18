class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=0;
        int f=0;
        int c=0;
        while(true){
            s=nums[s];
            f=nums[nums[f]];
            c++;
            if(s==f){
                break;
            }
        }
        int s2=0;
        while(s2!=f){
            s2=nums[s2];
            f=nums[f];
            if(s2==f){
                return f;
            }
        }
        return s;
    }
};