class Solution {
public:
    int day(int mid,vector<int>& weights){
        int s=0;
        int d=1;
        for(int i=0;i<weights.size();i++){
            s=s+weights[i];
            if(s>mid){
                d++;
                s=weights[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0;
        int r=0;
        for(int i=0;i<weights.size();i++){
            r=r+weights[i];
            l=max(l,weights[i]);
        }
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(day(mid,weights)<=days){
                ans=mid;
                r=mid-1;
            }
           
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};