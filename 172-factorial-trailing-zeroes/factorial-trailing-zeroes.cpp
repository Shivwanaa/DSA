class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        while(n){
            n=n/5;
            ans=ans+n;
        }
        return ans;
    }
};