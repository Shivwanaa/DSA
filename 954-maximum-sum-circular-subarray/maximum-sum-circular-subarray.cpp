class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ms=0,mins=0,minans=1e9;
        int mans=-1e9;
        int tot=0;
        for(int i=0;i<nums.size();i++){
            ms=ms+nums[i];
            mins=mins+nums[i];
            if(mins>0){
                mins=0;
            }
            tot=tot+nums[i];
            mans=max(mans,ms);
            minans=min(minans,mins);
            minans=min(minans,nums[i]);
            if(ms<0) ms=0;
        }
        cout<<minans;
        if(tot!=minans)
        return max(mans,tot-minans);
        return mans;
    }
};