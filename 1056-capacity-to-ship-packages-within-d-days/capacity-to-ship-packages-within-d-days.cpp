class Solution {
public:
    int check(int wt,vector<int>& weights){
        int d=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum=sum+weights[i];
            if(sum>wt){
                sum=weights[i];
                d++;
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0;
        int r=0;
        for(auto i:weights){
            l=max(i,l);
            r=r+i;
        }
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,weights)<=days){
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