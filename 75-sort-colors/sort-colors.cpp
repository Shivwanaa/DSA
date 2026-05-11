class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch national flag algo
        int l=0;//pointer for 0
        int h=nums.size()-1;//pointer for 2
        int m=0;//pointer for 1
        while(m<=h){
            if(nums[m]==0){
                swap(nums[m],nums[l]);
                l++;
                m++;
            }
            else if(nums[m]==1){
                m++;
            }
            else{
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
};