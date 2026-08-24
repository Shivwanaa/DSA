class Solution {
public:
    int hammingWeight(int n) {
        int c=n&1;
        // int a=n>>1;
        //cout<<a;
        while(n>0){
            c=c+((n>>1)&1); 
            n=n>>1;
        }
        return c;
    }
};