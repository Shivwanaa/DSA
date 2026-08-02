class Solution {
public:
    long long geth(int mid,vector<int>&piles){
        long long s=0;
        for(int i=0;i<piles.size();i++){
            s += (1LL * piles[i] + mid - 1) / mid;
        }
        return s;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int m=0;
        for(int i=0;i<piles.size();i++){
            m=max(m,piles[i]);
        }
        int l=1;
        int r=m;
        int ans;
        while(l<=r){
            int mid=(l+r)/2;
            cout<<mid;
            if(geth(mid,piles)<=h){
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