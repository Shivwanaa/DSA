class Solution {
public:
    int mySqrt(int x) {
        if(x==1){
            return 1;
        }
        int l=1;
        int r=x/2;
        int ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            if(mid*mid<=x){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};