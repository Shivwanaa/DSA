class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++){
            int c=i&1;
            int num=i;
            while(num>0){
                c+=(num>>1)&1;
                num=num>>1;
            }
            ans[i]=c;
        }
        return ans;
    }
};