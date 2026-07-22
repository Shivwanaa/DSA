class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        if(nums.size()==1){
            return {nums[0]};
        }
        int num1=nums[0];
        int num2=nums[1];
        int c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1){
                c1++;
            }
            else if(nums[i]==num2){
                c2++;
            }
            else if(c1==0){
                c1=1;
                num1=nums[i];
            }
            else if(c2==0){
                c2=1;
                num2=nums[i];
            }
            else{
                c1--;
                c2--;
            }
        }
        int count1=0,count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1){
                count1++;
            }
            else if(nums[i]==num2){
                count2++;
            }
        }
        if(count1>nums.size()/3){
            ans.push_back(num1);
        }
        if(count2>nums.size()/3){
            ans.push_back(num2);
        }
        return ans;
    }
};