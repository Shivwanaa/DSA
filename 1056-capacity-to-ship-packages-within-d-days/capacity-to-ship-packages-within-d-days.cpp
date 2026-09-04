class Solution {
public: 
    long long check(vector<int>& weights, int w){
        long long d=1;
        long long tot=0;
        for(auto i:weights){
            tot=tot+i;
            if(tot>w){
                d++;
                tot=i;
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int r=0;
        int l=0;
        for(int i=0;i<weights.size();i++){
            r=r+weights[i];
            l=max(l,weights[i]);
        }
        while(l<=r){
            long long mid=(l+r)/2;
            if(check(weights,mid)<=days){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};