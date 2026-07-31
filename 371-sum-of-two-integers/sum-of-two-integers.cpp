class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int curr=0;
        int carry=0;
        int mask = 0xFFFFFFFF;
        for(int i=0;i<32;i++){
            int d1=(a>>i)&1;
            int d2=(b>>i)&1;
            curr=d1^d2^carry;
            carry=(d1&d2)|(d1&carry)|(d2&carry);
            if(curr){
                ans=ans|(1<<i);
            }
        }
        if (ans>0x7FFFFFFF) {
            ans=~(ans^mask);
        }
        return ans;
    }
};