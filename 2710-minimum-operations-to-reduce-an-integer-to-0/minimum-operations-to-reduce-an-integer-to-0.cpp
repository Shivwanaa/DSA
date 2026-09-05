class Solution {
public:
    int minOperations(int n) {
        int ans=0;
        while(n){
            int x=floor(log2(n));
            int y=ceil(log2(n));
            int ans1=pow(2,x);
            int ans2=pow(2,y);
            n=min(abs(n-ans1),abs(n-ans2));
            ans++;
        }
        return ans;
    }
};